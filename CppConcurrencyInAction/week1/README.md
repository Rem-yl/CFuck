# Week1: 线程基础与 mutex 同步
## GPT大纲
**✅ 第 1 周目标**
- 学会创建和管理 std::thread
- 理解线程函数传参方式
- 掌握 std::mutex、std::lock_guard 同步原语
- 理解数据竞争（race condition）与线程安全

**🧠 一、核心概念讲解**
1. std::thread 基础使用
```c++
#include <iostream>
#include <thread>

void say_hello() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t(say_hello); // 创建线程
    t.join();                 // 等待线程执行完成
    return 0;
}
```

- `join()`: 阻塞当前主线程, 直到子线程执行完
- `detach()`: 将线程分离, 后台运行

2. 线程传参
```c++
void print_number(int x) {
    std::cout << "Number: " << x << std::endl;
}

std::thread t(print_number, 10);  // 传值

std::string msg = "hi";
std::thread t2([&](){ std::cout << msg << std::endl; }); // lambda传引用
std::thread t3(print_ref, std::ref(x));
```

3. 数据竞争     
数据竞争（race condition）：多个线程访问同一变量，并发写入时，结果不确定。

```c++
int counter = 0;
std::mutex mtx;

void increment() {
    for (int i = 0; i < 10000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // 自动上锁与释放
        ++counter;
    }
}
```