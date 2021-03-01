#ifndef _DUMP_GENERATOR_H_
#define _DUMP_GENERATOR_H_

#include <vector>
#include <functional>

class DumpGenerator {
public:
    DumpGenerator() = default;
    virtual ~DumpGenerator() = default;

    static void RegisterExceptionHook(std::function<void()> hook);
    static void ClearAllExceptionHooks();

protected:
    static const std::vector<std::function<void()>>& GetHooks();

private:
    static std::vector<std::function<void()>> hooks;
};

#endif
