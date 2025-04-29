# 13. 指针与引用
- 指针和引用的用法
- new运算符与常规定义的变量有无不同
- 常量指针
- 智能指针

## 1. 普通指针
**概念**

指针是一个变量，保存了另一个变量的内存地址。

**声明与使用**
```c++
int a = 10;
int* p = &a;  // p是指向int类型的指针

*p = 20;      // 修改p指向的值，相当于修改a
std::cout << a << std::endl;  // 输出20
```

**注意事项**
- 指针可以为 nullptr。
- 使用指针前必须初始化。
- 小心避免野指针（未初始化）和悬挂指针（指向已释放内存）。


## 2. 引用（Reference）

**概念**

引用是变量的别名，必须在声明时初始化，一旦绑定不能改变。

**声明与使用**
```c++
int a = 10;
int& ref = a;  // ref是a的引用
ref = 20;      // 相当于 a = 20
```

**特点**
- 必须初始化，且不可重新绑定。
- 语法简单，使用透明。
- 常用于函数参数和返回值，提高效率，避免拷贝。


## 4. 智能指针（Smart Pointer）

智能指针是 C++11 引入的，用于自动管理资源，避免内存泄漏，位于 <memory> 头文件中。

**4.1 std::unique_ptr**

独占式所有权：资源只能由一个 unique_ptr 拥有。
```c++
#include <memory>

std::unique_ptr<int> p1 = std::make_unique<int>(10);

*p1 = 20;
std::cout << *p1 << std::endl;  // 输出20
```

禁止拷贝，只能移动
```c++
std::unique_ptr<int> p2 = std::move(p1);
```

离开作用域时自动释放内存。

**4.2 std::shared_ptr**

共享式所有权：多个 shared_ptr 可以指向同一对象，使用引用计数管理生命周期。
```c++
#include <memory>

std::shared_ptr<int> p1 = std::make_shared<int>(10);
std::shared_ptr<int> p2 = p1;  // 引用计数 +1
```

查询引用计数：
```c++
std::cout << p1.use_count() << std::endl;
```
当引用计数为0时，资源被释放。

**4.3 std::weak_ptr**

弱引用：观察 shared_ptr 所管理的对象，不增加引用计数。
```c++
#include <memory>

std::shared_ptr<int> sp = std::make_shared<int>(100);
std::weak_ptr<int> wp = sp;  // wp观察sp

if (auto spt = wp.lock()) {  // lock尝试提升为shared_ptr
    std::cout << *spt << std::endl;
} else {
    std::cout << "Object expired." << std::endl;
}
```

通常用于解决shared_ptr循环引用的问题。

## 5. 常见错误总结
| 错误 | 说明 | 示例 |
| :--- | :--- | :--- | 
| 野指针 | 指针未初始化使用 | int* p; *p=5;|
| 悬挂指针 | 指向已释放对象 | 返回局部变量地址 |
| 内存泄露 | new 后没有delete | int* p = new int(5); |
| 引用非法访问 | 引用绑定到无效对象 | 返回局部变量的引用 |


