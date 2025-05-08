#pragma once

#include <string>
#include <sstream>

class Logger
{
  public:
    Logger() = default;
    Logger(const Logger &other) = delete;
    Logger &operator=(const Logger &other) = delete;

    template<typename T>
    void log(T&& msg) {
        std::ostringstream oss;
        oss << std::forward<T>(msg);      // 完美转发, 避免不需要的拷贝操作
        std::cout << "[LOG]: " << oss.str() << std::endl;
    }
};