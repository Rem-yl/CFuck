# 15.类的继承与多态
## 1. 继承（Inheritance）

**1. 基本概念**
- 继承是 代码复用 的一种机制。
- 一个新的类（子类 / 派生类）可以继承一个已有的类（父类 / 基类）的成员（属性和方法）。

**2. 基本语法**
```c++
class Base {
public:
    int x;
    void show() { /*...*/ }
};

class Derived : public Base {  // public继承
public:
    int y;
    void display() { /*...*/ }
};
```


**2. 多态（Polymorphism）**

1. 什么是多态
- 多态允许父类指针或引用指向子类对象。
- 真正调用的是子类的函数，而不是父类的函数 —— 运行时决定（而不是编译时）。


2. 实现条件
- 基类中定义虚函数（virtual）。
- 派生类中重写这个函数（可以加override）。
- 通过基类指针或引用调用。

```c++
class Animal {
public:
    virtual void sound() const {  // 虚函数
        std::cout << "Animal sound\n";
    }
};

class Dog : public Animal {
public:
    void sound() const override {
        std::cout << "Dog barks\n";
    }
};

void playSound(const Animal& a) {
    a.sound();   // 多态调用
}

int main() {
    Dog d;
    playSound(d);  // 输出 Dog barks
}
```

**✅ 注意**
- 必须有虚函数，否则就不是多态调用。
- 通常将基类的析构函数也声明为 virtual，避免内存泄漏。

**3. 虚函数表（V-Table）和运行机制**
- 编译时：编译器为含有虚函数的类生成一个虚函数表（vtable）。
- 运行时：对象根据自己的vtable来调用正确的函数（支持多态）。


## 4.抽象类（Abstract Class）
如果一个类里有纯虚函数（=0），那么这个类就是抽象类，不能实例化对象。
```c++
class Shape {
public:
    virtual void draw() = 0;  // 纯虚函数
};
```
子类必须重写所有纯虚函数，否则自身也成为抽象类。