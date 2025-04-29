# 14. 类和对象
类和对象是面向对象编程（OOP）的核心概念。类定义了对象的蓝图，而对象是类的实例。C++ 支持面向对象的编程，通过类和对象的机制来进行封装、继承、多态等操作。

## 1. 类的定义与对象的创建

类是对象的模板或蓝图。在 C++ 中，我们通过 class 或 struct 来定义一个类。类包含成员变量（属性）和成员函数（方法），用于描述和操作对象的状态和行为。

**类的定义**
```c++
class ClassName {
public:
    // 成员变量
    int memberVar;

    // 成员函数
    void memberFunction() {
        // 实现
    }
};
```

**创建对象**
```c++
ClassName objectName;  // 创建对象
objectName.memberVar = 10;  // 访问成员变量
objectName.memberFunction();  // 调用成员函数
```


## 2. 构造函数与析构函数
- 构造函数：用于初始化对象。构造函数没有返回值，与类名相同，可以是默认构造函数、带参构造函数或拷贝构造函数。
- 析构函数：在对象生命周期结束时自动调用，用于释放资源。析构函数没有参数，也没有返回值。

```c++
class MyClass {
public:
    MyClass() {  // 默认构造函数
        // 初始化操作
        std::cout << "Constructor called!" << std::endl;
    }

    MyClass(int x) {  // 带参构造函数
        std::cout << "Constructor with parameter " << x << std::endl;
    }

    ~MyClass() {  // 析构函数
        std::cout << "Destructor called!" << std::endl;
    }
};
```

## 3. 成员访问控制

C++ 中，类的成员可以通过访问控制符来设置访问权限。访问控制符有三个：public、private 和 protected。
- public: 公有成员，类外可以访问。
- private: 私有成员，类外不能直接访问。
- protected: 受保护成员，子类可以访问，但类外无法访问。


## 4. 静态成员

静态成员变量和静态成员函数属于类而非类的实例。它们在所有对象之间共享，而不是每个对象独立存在。
- 静态成员变量：在类的所有实例之间共享。
- 静态成员函数：只能访问静态成员变量和静态成员函数，不能访问非静态成员。

```c++
class MyClass {
public:
    static int staticVar;  // 静态成员变量

    static void staticFunction() {  // 静态成员函数
        std::cout << "Static function called!" << std::endl;
    }
};

// 静态成员的定义
int MyClass::staticVar = 0;
```

## 5. 构造函数的初始化列表

构造函数的初始化列表用于初始化成员变量，尤其是常量成员或引用类型的成员。初始化列表在构造函数体执行之前就被
```c++
class MyClass {
private:
    const int constVar;
    int& refVar;

public:
    MyClass(int x, int& ref) : constVar(x), refVar(ref) {}  // 使用初始化列表
};
```

## 6. 构造函数详解

**构造函数基本特性**

- 没有返回类型：构造函数没有返回值，也不能定义返回类型。
- 与类名相同：构造函数的名称与类名相同。
- 自动调用：每次创建对象时，构造函数会自动调用。

**默认构造函数**

默认构造函数（无参构造函数）是在创建对象时未传入参数时自动调用的构造函数。编译器会为没有显式定义构造函数的类提供一个默认构造函数，通常会初始化成员变量为默认值（对于内置类型成员变量，默认构造函数不做初始化）。

```c++
class MyClass {
public:
    MyClass() {
        // 默认构造函数，不传参数时调用
        std::cout << "Default constructor!" << std::endl;
    }
};
```
如果显式定义了构造函数，编译器将不再自动生成默认构造函数。

**构造函数初始化列表**

构造函数初始化列表是用来初始化类的成员变量的，它比在构造函数体内赋值更高效，特别是当成员是常量或引用类型时，必须通过初始化列表来初始化。
- 常量成员变量：只能通过初始化列表初始化，不能在构造函数体内初始化。
- 引用成员变量：必须通过初始化列表初始化。

```c++
class MyClass {
private:
    const int x;
    int& y;

public:
    // 使用初始化列表初始化成员变量
    MyClass(int val1, int& ref) : x(val1), y(ref) {
        std::cout << "Constructor with initialization list!" << std::endl;
    }

    void showValues() {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
};
```

**拷贝构造函数**

拷贝构造函数用于通过现有对象来创建新对象。

它通常用于对象的传递、返回或者拷贝时调用。**拷贝构造函数的默认行为是逐成员拷贝**，但有时我们需要自定义拷贝构造函数来处理深拷贝等。

```c++
class MyClass {
private:
    int* data;

public:
    MyClass(int value) {
        data = new int(value);  // 动态分配内存
    }

    // 拷贝构造函数
    MyClass(const MyClass& other) {
        data = new int(*other.data);  // 深拷贝
    }

    ~MyClass() {
        delete data;  // 释放动态内存
    }
};
```

**移动构造函数**

移动构造函数用于“窃取”另一个对象的资源，并且不复制资源。它通常在需要转移所有权时使用。移动构造函数通常在对象返回时，或者通过 `std::move()` 转移资源时被调用。
```c++
class MyClass {
private:
    int* data;

public:
    MyClass(int value) {
        data = new int(value);
    }

    // 移动构造函数
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;  // 置空源对象的指针，避免析构时释放资源
    }

    ~MyClass() {
        delete data;
    }
};
```

**委托构造函数**

委托构造函数允许一个构造函数调用另一个构造函数。它通常用于减少代码重复，尤其是当多个构造函数有相似的初始化代码时。
```c++
class MyClass {
private:
    int x;
    int y;

public:
    MyClass() : MyClass(0, 0) {}  // 委托构造函数，调用带参数的构造函数

    MyClass(int a, int b) : x(a), y(b) {
        std::cout << "Constructor with parameters!" << std::endl;
    }
};
```

**构造函数与虚函数**

构造函数不能是虚函数，因为虚函数的机制依赖于类的继承结构，而构造函数在对象构造时被调用，此时类的继承结构还没有完全构建起来。
```c++
class Base {
public:
    virtual void show() {}  // 可以是虚函数
    Base() { show(); }  // 构造函数不能是虚函数
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class!" << std::endl;
    }
};
```