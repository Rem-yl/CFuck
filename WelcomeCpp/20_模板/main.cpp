#include <iostream>
#include <string>

template<typename T>
T maxValue(T a, T b) {
    static_assert(
        std::is_same<T, int>::value ||
        std::is_same<T, float>::value ||
        std::is_same<T, std::string>::value,
        "T must be int, float, or std::string"
    );

    return std::max<T>(a, b);
}

template<typename T>
void swapValues(T& a, T& b) {
    // T& tmp = a; // 创建引用tmp 指向 a
    T tmp = a;
    a = b;
    b = tmp;
}

void test1() {
    int a = 10;
    int b = 20;
    int c = maxValue<int>(a, b);

    std::string a_str = "hello";
    std::string b_str = "a";
    std::string c_str = maxValue<std::string>(a_str, b_str);

    std::cout << c << std::endl;
    std::cout << c_str << std::endl;
}

void test2() {
    int a = 10;
    int b = 20;
    swapValues<int>(a, b);
    std::cout << "a: " << a << ", b: " << b << std::endl;

    std::string a_str = "hello";
    std::string b_str = "a";
    swapValues<std::string>(a_str, b_str);
    std::cout << "a_str: " << a_str << ", b_str: " << b_str << std::endl;
}


int main() {
    test1();
    test2();

    return 0;
}