#include <iostream>
#include "logger.h"

void test1() {
    int x = 5;
    int y = std::move(x);
}

std::string betterConcat(std::string&& a, std::string&& b) {
    a += std::move(b);
    return std::move(a);
}

template<typename T, typename... Args>
std::shared_ptr<T> makeMyShared(Args&&... args) {
    return std::make_shared<T>(std::forward<Args>(args)...);
}

void test2() {
    Logger logger;
    logger.log("hello");
}

int main() {
    test2();
    return 0;
}