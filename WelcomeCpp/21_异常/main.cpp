#include "StudentException.h"
#include "ConfigLoader.h"
#include <iostream>
#include <stdexcept>
#include <string>

void test1() {
    int x, y;
    std::cout << "输入第一个整数: ";
    std::cin >> x;
    std::cout << "输入第二个整数: ";
    std::cin >> y;

    if (y == 0) {
        throw std::runtime_error("Error: 除数不能为零");
    }

    int res = x / y;
    std::cout << "res: " << res << std::endl;
}

void test2() {
    float x;
    std::cout << "输入成绩: ";
    std::cin >> x;
    
    if (x < 0.0 or x > 100.0) {
        std::string str = std::to_string(x);
        const char* cstr = str.c_str();
        throw StudentException(cstr);
    }
}

void test3() {
    std::string file_name = "/Users/yule/Desktop/opera/2_code/CFuck/WelcomeCpp/21_异常/config.txt";
    ConfigLoader loader(file_name);
    loader.load();
    std::string value = loader.getValue("host");

    std::cout << value << std::endl;
}

int main() {
    // test1();
    // test2();
    test3();
    return 0;
}