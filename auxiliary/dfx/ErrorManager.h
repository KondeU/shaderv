#ifndef _ERROR_MANAGER_H_
#define _ERROR_MANAGER_H_

#include <string>
#include "Logger.h"

class ErrorManager final {
public:
    explicit ErrorManager(Logger& logger);
    ~ErrorManager();

    enum class ErrorType {
        EMET_DEBUG       = 0,
        EMET_INFORMATION = 1,
        EMET_WARNING     = 2,
        EMET_ERROR       = 3,
        EMET_FATAL       = 4,
        TOTAL            = 5
    };

    void PutError(ErrorType type, const std::string& message,
        const std::string& file, const std::string& function, int line) const;

private:
    Logger& logger;

    #ifdef _DEBUG
    static const ErrorType LIMIT = ErrorType::EMET_DEBUG;
    #else
    static const ErrorType LIMIT = ErrorType::EMET_INFORMATION;
    #endif
};

#endif
