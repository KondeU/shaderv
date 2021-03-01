#include "DFX.h"
#include <chrono>
#include <string>
#include <vector>
#include <memory>
#include "Logger.h"
#include "ErrorManager.h"
#include "DumpGenerator.h"

namespace {
    std::unique_ptr<Logger> g_logger;
    std::unique_ptr<ErrorManager> g_errman;
}

long long DFX::initTimeStamp = 0;

long long DFX::GetInitializedTimeStamp()
{
    return initTimeStamp;
}

void DFX::Init(bool multiSupport, const std::string& logSavedPathPrefix)
{
    if (initTimeStamp <= 0) {
        auto now = std::chrono::system_clock::now();
        auto dur = now.time_since_epoch();
        auto dif = std::chrono::duration_cast<std::chrono::nanoseconds>(dur).count();
        initTimeStamp = dif;

        std::string logFile(logSavedPathPrefix +
            (multiSupport ? (std::to_string(dif) + ".log") : "runtime.log"));

        g_logger = std::make_unique<Logger>(logFile);
        g_errman = std::make_unique<ErrorManager>(*g_logger);
    }
}

void DFX::Deinit()
{
    if (initTimeStamp > 0) {
        g_errman.reset();
        g_logger.reset();

        // Deinit will destruct the g_logger, we should clear all exception hooks
        // to ensure that invalid hooks function are not to called when crash.
        DumpGenerator::ClearAllExceptionHooks();
        initTimeStamp = 0;
    }
}

void DFX::EnableMemoryLeakDebugTracing()
{
    #if defined(_MSC_VER) && defined(_DEBUG)
    // Tracing memory leaks, we can call _CrtSetBreakAlloc({ALLOC_POINT}) to
    // set a breakpoint at the leak location for debugging.
    // NB: The memory leak information only shown in the output window of VS.
    // NB: It may not be able to trace the memory leaks in dynamic libraries!
    _CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
    #endif
}

void DFX::RegisterExceptionHook(void(*hook)(void*), void* param)
{
    DumpGenerator::RegisterExceptionHook([hook, param]() { hook(param); });
}

void DFX::PutError(ErrorType type, const std::string& message,
    const std::string& file, const std::string& function, int line)
{
    if (g_errman) {
        g_errman->PutError(static_cast<
            ErrorManager::ErrorType>(type),
            message, file, function, line);
    }
}
