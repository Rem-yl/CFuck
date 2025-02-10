#include <iostream>

class Example {
private:
    // 成员声明顺序：a 先声明，b 后声明
    int a;
    int b;

public:
    // 构造函数，错误示例：初始值顺序与声明顺序不一致且用后声明的成员初始化先声明的成员
    Example(int value) : b(value), a(b) {
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }

    // 构造函数，正确示例：初始值顺序与声明顺序一致且避免用成员初始化其他成员
    Example(int value1, int value2) : a(value1), b(value2) {
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }
};

int main() {
    // 调用错误示例的构造函数
    std::cout << "错误示例：" << std::endl;
    Example obj1(5);

    // 调用正确示例的构造函数
    std::cout << "正确示例：" << std::endl;
    Example obj2(10, 20);

    return 0;
}