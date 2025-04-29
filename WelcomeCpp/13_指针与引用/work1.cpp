#include <iostream>
#include <memory>

void test1() {
    int* p;
    *p = 10;    // error: 普通指针声明未初始化。
}

void test2() {
    int* p = new int(20);
    std::cout << *p << std::endl;
    delete p;   // new出来的内存记得删除, 否则会内存泄露
}

void test3() {
    int a = 5;
    int* p = &a;
    delete p; // error: 栈变量不能删除
}

void test4() {
    std::shared_ptr<int> sp = std::make_shared<int>(30);
    std::cout << *sp << std::endl;  // 超出作用域时自动释放内存
}

void test5() {
    std::unique_ptr<int> up = std::unique_ptr<int>(new int(40));
    std::cout << *up << std::endl;
}

void test6() {
    std::shared_ptr<int> p1 = std::make_shared<int>(100);
    std::shared_ptr<int> p2 = p1;
    std::cout << p1.use_count() << std::endl;
    p2.reset();
    std::cout << p1.use_count() << std::endl;
}

void test7() {
    std::unique_ptr<int> p1 = std::unique_ptr<int>(new int(10));
    // std::unique_ptr<int> p2 = p1;   // error: 禁止拷贝
    std::unique_ptr<int> p2 = std::move(p1);    // 可以移动
    // std::cout << *p1 << std::endl;  // error: std::move(p1) 会将 p1 的所有权转移给 p2，此时 p1 变为空指针
}

int* allocateInt(int value) {
    int* p = new int(value);
    return p;
}

void deallocate(int* p) {
    if (p != nullptr) {
        delete p;
        p = nullptr;
    }
}

int main() {
    test7();
    return 0;
}