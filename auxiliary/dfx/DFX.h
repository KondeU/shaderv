#ifndef _DFX_H_
#define _DFX_H_

#ifdef _WIN32
#ifdef _DFX_API
#define DFX_API __declspec(dllexport)
#else
#define DFX_API __declspec(dllimport)
#endif
#else
#define DFX_API
#endif

#include <string>

// Memory leak debug tracing (currently only MSVC supported!)
#if defined(_MSC_VER) && defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

class DFX_API DFX final {
public:
    enum class ErrorType {
        D = 0, // Debug
        I = 1, // Information
        W = 2, // Warning
        E = 3, // Error
        F = 4  // Fatal
    };

    static long long GetInitializedTimeStamp();

    static void Init(bool multiSupport = false,
        const std::string& logSavedPathPrefix = "");
    static void Deinit();

    static void EnableMemoryLeakDebugTracing();

    static void RegisterExceptionHook(void(*hook)(void*), void* param);

    static void PutError(ErrorType type, const std::string& message,
        const std::string& file, const std::string& function, int line);

private:
    DFX() = default;
    ~DFX() = default;

    static long long initTimeStamp;
};

#define ERR_D(s) DFX::PutError(DFX::ErrorType::D, s, __FILE__, __FUNCTION__, __LINE__)
#define ERR_I(s) DFX::PutError(DFX::ErrorType::I, s, __FILE__, __FUNCTION__, __LINE__)
#define ERR_W(s) DFX::PutError(DFX::ErrorType::W, s, __FILE__, __FUNCTION__, __LINE__)
#define ERR_E(s) DFX::PutError(DFX::ErrorType::E, s, __FILE__, __FUNCTION__, __LINE__)
#define ERR_F(s) DFX::PutError(DFX::ErrorType::F, s, __FILE__, __FUNCTION__, __LINE__)

#endif
