#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <fstream>
#include <vector>
#include <string>
#include <atomic>
#include <thread>
#include <mutex>

class Logger final {
public:
    explicit Logger(const std::string& file);
    ~Logger();

    void D(const std::string& log);
    void I(const std::string& log);
    void W(const std::string& log);
    void E(const std::string& log);
    void F(const std::string& log);

private:
    std::string GetCurrentSystemTime() const;
    std::string GetCurrentThreadId() const;

    long long GetCurrentSteadyTimeCount() const;

    void PushLog(const std::string& fullLog);
    void SwapLogs(std::vector<std::string>& swapBuffer);

    void ThreadFunc();
    void ExceptionHook();

    void OutputRemains();

    std::ofstream fout;
    std::atomic_bool exit;
    std::thread thread;
    std::mutex mutex;

    std::vector<std::string> logs;
    std::vector<std::string> logt;

    static constexpr size_t MAX_LOGS_BUFFER = 4096;
};

#endif
