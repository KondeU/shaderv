#include "Logger.h"
#include <sstream>
#include <iomanip>
#include <chrono>
#include <algorithm>
#include "DumpGenerator.h"

Logger::Logger(const std::string& file)
{
    logs.reserve(MAX_LOGS_BUFFER);
    logt.reserve(MAX_LOGS_BUFFER);

    exit = false;
    fout.open(file);
    DumpGenerator::RegisterExceptionHook(
        std::bind(&Logger::ExceptionHook, this));
    thread = std::thread(
        std::bind(&Logger::ThreadFunc, this));
}

Logger::~Logger()
{
    exit = true;
    if (thread.joinable()) {
        thread.join();
    }
    OutputRemains();
    fout.close();

    logs.resize(0);
    logt.resize(0);
}

void Logger::D(const std::string& log)
{
    PushLog(
        "[" + GetCurrentSystemTime() + "]" +
        "[" + GetCurrentThreadId()   + "]" +
        "[D]" + log + "\r\n");
}

void Logger::I(const std::string& log)
{
    PushLog(
        "[" + GetCurrentSystemTime() + "]" +
        "[" + GetCurrentThreadId()   + "]" +
        "[I]" + log + "\r\n");
}

void Logger::W(const std::string& log)
{
    PushLog(
        "[" + GetCurrentSystemTime() + "]" +
        "[" + GetCurrentThreadId()   + "]" +
        "[W]" + log + "\r\n");
}

void Logger::E(const std::string& log)
{
    PushLog(
        "[" + GetCurrentSystemTime() + "]" +
        "[" + GetCurrentThreadId()   + "]" +
        "[E]" + log + "\r\n");
}

void Logger::F(const std::string& log)
{
    PushLog(
        "[" + GetCurrentSystemTime() + "]" +
        "[" + GetCurrentThreadId()   + "]" +
        "[F]" + log + "\r\n");
}

std::string Logger::GetCurrentSystemTime() const
{
    auto now = std::chrono::system_clock::now();
    auto dur = now.time_since_epoch();
    auto dif = std::chrono::duration_cast<std::chrono::milliseconds>(dur).count();

    time_t time = std::chrono::system_clock::to_time_t(now);
    unsigned int ms = dif % 1000;

    struct tm localTime = { 0 };
    #ifdef _WIN32
    #ifdef _MSC_VER
    localtime_s(&localTime, &time);
    #else
    memcpy(&localTime, std::localtime(&time), sizeof(localTime));
    #endif
    #else
    localtime_r(&time, &localTime);
    #endif

    std::stringstream ss;
    ss << std::put_time(&localTime, "%Y-%m-%d.%H:%M:%S.")
       << std::setfill('0') << std::setw(3) << ms;
    return ss.str();
}

std::string Logger::GetCurrentThreadId() const
{
    std::stringstream ss;
    ss << std::this_thread::get_id();
    return ss.str();
}

long long Logger::GetCurrentSteadyTimeCount() const
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count();
}

void Logger::PushLog(const std::string& fullLog)
{
    std::lock_guard<std::mutex> lock(mutex);
    if (logs.size() >= MAX_LOGS_BUFFER) {
        logs.erase(logs.begin());
        logs.emplace_back("[LOG_ROLLBACK!]" + fullLog);
    } else {
        logs.emplace_back(fullLog);
    }
}

void Logger::SwapLogs(std::vector<std::string>& swapBuffer)
{
    std::lock_guard<std::mutex> lock(mutex);
    swapBuffer.swap(logs);
}

void Logger::ThreadFunc()
{
    while (!exit) {
        long long beg = GetCurrentSteadyTimeCount();
        logt.clear();
        SwapLogs(logt);
        if (fout) {
            for (const std::string& log : logt) {
                fout << log;
            }
        }
        long long end = GetCurrentSteadyTimeCount();

        long long delay = std::max(10LL - (end - beg), 1LL); // 100Hz
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void Logger::ExceptionHook()
{
    // "\r\n" for all platform
    fout << "\r\nCRASH REMAIN LOGS\r\n";
    OutputRemains();
}

void Logger::OutputRemains()
{
    std::vector<std::string> remaint(logt);
    for (const std::string& remain : remaint) {
        fout << remain;
    }

    std::vector<std::string> remains(logs);
    for (const std::string& remain : remains) {
        fout << remain;
    }

    // "endl" for force flush!
    fout << std::endl;
}
