#include "DumpGenerator.h"
#include <fstream>
#include <string>

enum DumpType {
    NORMAL,
    MEMORY,
    FULL
};

DumpType GetDumpTypeFromDumpConfigFile()
{
    DumpType dumpType = NORMAL;

    #ifdef _DEBUG
    std::ifstream fin("dump.cfg");
    if (fin) {
        std::string dumpConfig;
        fin >> dumpConfig;
        if (dumpConfig == "Normal") {
            dumpType = NORMAL;
        } else if (dumpConfig == "Memory") {
            dumpType = MEMORY;
        } else if (dumpConfig == "Full") {
            dumpType = FULL;
        } else {
            dumpType = NORMAL;
        }
        fin.close();
    }
    #endif

    return dumpType;
}

#ifdef _WIN32

#include <cstdio>
#include <Windows.h>
#include <DbgHelp.h>

#pragma comment(linker,                     \
"/manifestdependency:\""                    \
"type='win32' "                             \
"name='Microsoft.Windows.Common-Controls' " \
"version='6.0.0.0' "                        \
"processorArchitecture='*' "                \
"publicKeyToken='6595b64144ccf1df' "        \
"language='*'\"")

namespace {
    MINIDUMP_TYPE g_windowsMiniDumpType = MiniDumpNormal;
}

class DumpGeneratorImpl final : public DumpGenerator {
public:
    DumpGeneratorImpl()
    {
        g_windowsMiniDumpType =
            DumpTypeConverter(GetDumpTypeFromDumpConfigFile());
        if (CatchAllExceptDump() != TRUE) {
            MessageBox(NULL, TEXT("Dump catcher setup error!"),
                TEXT("DFX"), MB_ICONWARNING);
        }
    }

    ~DumpGeneratorImpl() override
    {
    }

private:
    static MINIDUMP_TYPE DumpTypeConverter(DumpType dumpType)
    {
        switch (dumpType) {
            case NORMAL:
                return MiniDumpNormal;
            case MEMORY:
                return MiniDumpWithFullMemory;
            case FULL:
                return static_cast<MINIDUMP_TYPE>(0x00009B67);
        }
        return MiniDumpNormal;
    }

    static BOOL CatchAllExceptDump()
    {
        SetUnhandledExceptionFilter(ExceptionHandler);

        // UCRT hook code
        #ifdef _M_IX86
        // Code for x86:
        // 33 C0     xor eax,eax
        // C2 04 00  ret 4
        unsigned char szExecute[] = { 0x33, 0xC0, 0xC2, 0x04, 0x00 };
        #elif _M_X64
        // Code for x64:
        // 33 C0     xor eax,eax
        // C3        ret
        unsigned char szExecute[] = { 0x33, 0xC0, 0xC3 };
        #else
        // Only works for x86 and x64
        return FALSE;
        #endif

        HMODULE hKernel32 = LoadLibrary(TEXT("kernel32.dll"));
        if (hKernel32 == NULL) {
            return FALSE;
        }

        // The function is ANSI version
        void* addr = GetProcAddress(hKernel32, "SetUnhandledExceptionFilter");
        if (addr) {
            DWORD dwOldFlag = 0;
            DWORD dwTempFlag = 0;
            SIZE_T bytesWritten = 0;

            BOOL suc = FALSE;
            suc = VirtualProtect(addr, sizeof(szExecute),
                PAGE_EXECUTE_READWRITE, &dwOldFlag);
            suc = WriteProcessMemory(GetCurrentProcess(),
                addr, szExecute, sizeof(szExecute), &bytesWritten);
            suc = VirtualProtect(addr, sizeof(szExecute), dwOldFlag, &dwTempFlag);
            return TRUE;
        }
        return FALSE;
    }

    static LONG WINAPI ExceptionHandler(LPEXCEPTION_POINTERS lpExceptionPointers)
    {
        for (const auto& hookFunc : GetHooks()) {
            if (hookFunc) {
                try {
                    hookFunc();
                } catch (...) {
                    // Catch the exception of the hook function to avoid the failure to
                    // generate a dump file due to the crash caused by the hook function.
                }
            }
        }

        if (IsDebuggerPresent()) {
            return EXCEPTION_CONTINUE_SEARCH;
        }
        return CrashFinishWork(GenerateMiniDump(lpExceptionPointers));
    }

    static LONG GenerateMiniDump(PEXCEPTION_POINTERS pExceptionPointers)
    {
        HMODULE hDbgHelp = LoadLibrary(TEXT("DbgHelp.dll"));
        if (hDbgHelp == NULL) {
            return EXCEPTION_CONTINUE_SEARCH;
        }

        using MiniDumpWriteDumpPtr = BOOL(WINAPI*)(
            HANDLE, DWORD, HANDLE, MINIDUMP_TYPE,
            PMINIDUMP_EXCEPTION_INFORMATION,
            PMINIDUMP_USER_STREAM_INFORMATION,
            PMINIDUMP_CALLBACK_INFORMATION);
        MiniDumpWriteDumpPtr pfnMiniDumpWriteDump =
            reinterpret_cast<MiniDumpWriteDumpPtr>(
                GetProcAddress(hDbgHelp, "MiniDumpWriteDump"));
        if (pfnMiniDumpWriteDump == NULL) {
            FreeLibrary(hDbgHelp);
            return EXCEPTION_CONTINUE_SEARCH;
        }

        TCHAR szPrefix[] = TEXT("crash");
        TCHAR szFileName[MAX_PATH] = { 0 };

        #ifdef UNICODE
        #define tprintf swprintf_s
        #else
        #define tprintf sprintf_s
        #endif

        #ifdef _DEBUG
        SYSTEMTIME stComputerLocalTime;
        GetLocalTime(&stComputerLocalTime);
        tprintf(szFileName, TEXT("%s-%04d%02d%02d-%02d%02d%02d.dmp"), szPrefix,
            stComputerLocalTime.wYear,   stComputerLocalTime.wMonth,
            stComputerLocalTime.wDay,    stComputerLocalTime.wHour,
            stComputerLocalTime.wMinute, stComputerLocalTime.wSecond);
        #else
        tprintf(szFileName, TEXT("%s.dmp"), szPrefix);
        #endif

        HANDLE hDumpFile = CreateFile(szFileName, GENERIC_WRITE, FILE_SHARE_READ,
            NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (hDumpFile == INVALID_HANDLE_VALUE) {
            FreeLibrary(hDbgHelp);
            return EXCEPTION_CONTINUE_SEARCH;
        }

        MINIDUMP_EXCEPTION_INFORMATION mdei;
        mdei.ThreadId = GetCurrentThreadId();
        mdei.ExceptionPointers = pExceptionPointers;
        mdei.ClientPointers = FALSE;
        pfnMiniDumpWriteDump(
            GetCurrentProcess(),
            GetCurrentProcessId(),
            hDumpFile, g_windowsMiniDumpType,
            (pExceptionPointers ? &mdei : NULL), NULL, NULL);

        CloseHandle(hDumpFile);
        FreeLibrary(hDbgHelp);
        return EXCEPTION_EXECUTE_HANDLER;
    }

    static LONG CrashFinishWork(LONG next)
    {
        #ifndef _DEBUG
        WinExec("CrashReporter.exe crash.dmp", SW_SHOW);
        #endif
        return next;
    }
};

#else

class DumpGeneratorImpl final : public DumpGenerator {
public:
    DumpGeneratorImpl() = default;
    ~DumpGeneratorImpl() = default;
};

#endif

namespace {
    DumpGeneratorImpl g_dumpGenerator;
}

std::vector<std::function<void()>> DumpGenerator::hooks;

void DumpGenerator::RegisterExceptionHook(std::function<void()> hook)
{
    hooks.emplace_back(hook);
}

void DumpGenerator::ClearAllExceptionHooks()
{
    hooks.clear();
}

const std::vector<std::function<void()>>& DumpGenerator::GetHooks()
{
    return hooks;
}
