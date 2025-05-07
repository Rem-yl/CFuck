# 20. 模板

## 1. 函数模板（Function Template）

函数模板用于生成与类型无关的函数。例如，实现一个通用的交换函数：
```c++
template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```

## 2. 类模板（Class Template）

类模板用于生成与类型无关的类。例如，实现一个简单的泛型数组容器：
```c++
template <typename T>
class MyArray {
private:
    T data[100];
    int size;
public:
    MyArray(): size(0) {}
    void push_back(const T& value) {
        data[size++] = value;
    }
    T get(int index) const {
        return data[index];
    }
};
```

**1. 类模板与成员函数的定义分离**

类模板的成员函数一般在类定义中实现，也可以像普通类一样在类外实现，但必须带上模板参数：
```c++
template<typename T>
class MyClass {
public:
    void show();
};

template<typename T>
void MyClass<T>::show() {
    std::cout << "Template class" << std::endl;
}
```

**3. 模板类的特化（Template Specialization）**

有时候你希望某些类型有特别实现：

```c++
template<typename T>
class Printer {
public:
    void print(T val) {
        std::cout << val << std::endl;
    }
};

// 特化：当 T 为 bool 时使用不同的输出
template<>
class Printer<bool> {
public:
    void print(bool val) {
        std::cout << (val ? "true" : "false") << std::endl;
    }
};
```