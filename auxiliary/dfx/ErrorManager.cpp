#include "ErrorManager.h"
#include <sstream>
#include <algorithm>

#ifdef _WIN32
#include <Windows.h>
#endif

ErrorManager::ErrorManager(Logger& logger) : logger(logger)
{
}

ErrorManager::~ErrorManager()
{
}

void ErrorManager::PutError(ErrorType type, const std::string& message,
    const std::string& file, const std::string& function, int line) const
{
    std::string name = file.substr(file.find_last_of("/\\") + 1);

    if (type >= LIMIT && type < ErrorType::TOTAL) {
        std::stringstream ss;
        ss << "[" << name << "," << function << "," << line << "]: " << message;

        switch (type) {
            case ErrorType::EMET_DEBUG:
                logger.D(ss.str());
                break;

            case ErrorType::EMET_INFORMATION:
                logger.I(ss.str());
                break;

            case ErrorType::EMET_WARNING:
                logger.W(ss.str());
                break;

            case ErrorType::EMET_ERROR:
                logger.E(ss.str());
                #ifdef _WIN32
                MessageBoxA(NULL, ss.str().c_str(),
                    "INTERNAL ERROR", MB_ICONWARNING);
                #endif
                break;

            case ErrorType::EMET_FATAL:
                logger.F(ss.str());
                #ifdef _WIN32
                MessageBoxA(NULL, ss.str().c_str(),
                    "INTERNAL FATAL", MB_ICONERROR);
                #endif
                break;
        }
    }
}
