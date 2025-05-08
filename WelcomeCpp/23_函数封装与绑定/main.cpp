#include <functional>
#include <iostream>
#include <string>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int power(int base, int exp) {
    return std::pow(base, exp);
}

class Printer {
public:
    void print(const std::string& msg) const {
        std::cout << msg << std::endl;
    }
};


void test1() {
    int a = 5;
    int b = 3;
    std::function<int(int, int)> f = add;
    std::cout << f(a, b) << std::endl;
    f = sub;
    std::cout << f(a, b) << std::endl;
}

void test2() {
    auto square = std::bind(power, 2, std::placeholders::_1);
    int n = 3;
    std::cout << square(n) << std::endl;
}

void test3() {
    Printer p;
    auto f = std::bind(&Printer::print, p, std::placeholders::_1);
    f("hello");

    std::function<void(Printer&, const std::string&)> fn = std::mem_fn(&Printer::print);
    fn(p, "rem");
}

int main() {
    test1();
    test2();
    test3();
    return 0;
}