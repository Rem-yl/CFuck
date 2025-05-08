# 21. 函数封装与绑定
## 1. 背景：为什么需要函数封装？

C++ 中函数是一等对象，但：
- 普通函数指针不易封装复杂行为。
- 成员函数调用需要对象参与，不易传递。
- 回调机制或策略模式中，需要统一“可调用对象”的接口。

所以，引入：
- `std::function`：统一封装可调用对象。
- `std::bind`：提前绑定参数生成新的可调用对象。
- `lambda`：内联轻量定义行为逻辑。

## 2. `std::function`

`std::function` 是一个泛型函数封装器，可存储：
- 普通函数
- 成员函数（配合 bind 或 mem_fn）
- lambda 表达式
- 函数对象（重载 operator() 的类）

```c++
#include <functional>
#include <iostream>

int add(int a, int b) { return a + b; }

int main() {
    std::function<int(int, int)> f = add;
    std::cout << f(3, 4) << std::endl; // 输出 7
}
```

## 3. `std::bind`

`std::bind` 用于生成一个新的函数对象，可以：
- 绑定某些参数值
- 绑定成员函数和对象
- 延迟调用

**✅ 示例 1：绑定参数**
```c++
int add(int a, int b) { return a + b; }

auto add5 = std::bind(add, 5, std::placeholders::_1);
// 绑定 a=5，b由调用者传入

std::cout << add5(3);  // 输出 8
```

**✅ 示例 2：绑定成员函数**
```c++
class Printer {
public:
    void print(const std::string& msg) const {
        std::cout << msg << std::endl;
    }
};

Printer p;
auto f = std::bind(&Printer::print, p, std::placeholders::_1);
f("Hello");  // 输出 Hello
```

## 4. Lambda 表达式
C++11 引入的内联函数对象，简洁定义行为。
**基本语法**
```c++
[capture](parameter_list) -> return_type {
    function_body
};
```
- capture：捕获外部变量方式
- parameter_list：参数列表，像普通函数一样
- return_type（可省略）：返回值类型
- function_body：函数体代码

```c++
auto square = [](int x) { return x * x; };
std::cout << square(5);  // 输出 25
```

**示例: 捕获变量**
1. 值捕获 [=]（拷贝）
```c++
int x = 10;
auto f = [=]() {
    std::cout << x << std::endl;
};
f();  // 输出 10
```

2. 引用捕获 [&]
```c++
int x = 10;
auto f = [&]() {
    x = 20;
};
f();
std::cout << x;  // 输出 20
```

3. 捕获部分变量
```c++
int a = 5, b = 10;
auto f = [a, &b]() {
    std::cout << a << ", " << b << std::endl;
    b = 100;
};
f();  // 输出 5, 10
```

4. 结合捕获和参数
```c++
#include <iostream>

int main() {
    int total = 0;

    auto adder = [&total](int x) {
        total += x;
    };

    adder(5);
    adder(10);
    std::cout << "total: " << total << std::endl;  // 输出 15
}
```

## 5. `std::mem_fn`
简化成员函数指针的调用：
```c++
#include <functional>

A a;
auto f = std::mem_fn(&A::say);
f(a, 10);  // 等价于 a.say(10)
```

```c++
#include <functional>
#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    std::function<int(int)> add5 = std::bind(add, 5, std::placeholders::_1);
    std::cout << add5(3); // 输出 8
}
```