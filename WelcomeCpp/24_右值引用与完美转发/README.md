# 24. 右值引用与完美转发
## 1. 左值
左值是有名字、可寻址、可以出现在赋值号左边的值。它表示对象的身份。

✅ 特点：
- 有持久的内存地址。
- 可以取地址（如 &x）。
- 通常是变量或函数返回的引用。

✅ 示例：
```c++
int x = 10;
int* p = &x;     // x 是左值
x = 20;          // 左值可以被赋值
```

## 2. 右值
右值是临时的、不可寻址、不能出现在赋值号左边的值。它表示对象的值本身。

✅ 特点：
- 没有持久的内存地址。
- 不能取地址（不能对 3 使用 &）。
- 常见于临时对象、字面量、表达式的结果等。

✅ 示例：
```c++
int y = 5 + 3;   // 5+3 是右值
int z = 100;     
z = 50;          // 50 是右值
```

## 3. 通用引用（万能引用）
**定义**
当我们使用 T&& 作为模板参数时，它既可以绑定到左值也可以绑定到右值，这被称为通用引用（Universal Reference）。
```c++
template<typename T>
void wrapper(T&& arg) {
    // arg 是通用引用
}
```

这依赖于 引用折叠规则：
- T& & → T&
- T& && → T&
- T&& & → T&
- T&& && → T&&

## 4. 移动构造函数 & 移动赋值运算符
为提高性能，C++11 引入了移动语义，避免不必要的深拷贝，尤其在资源管理类中非常有用。

1. 移动构造函数
```c++
class MyString {
public:
    char* data;

    MyString(const char* s) {
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }

    // 移动构造函数
    MyString(MyString&& other) noexcept {
        data = other.data;
        other.data = nullptr;
    }

    ~MyString() {
        delete[] data;
    }
};
```

2. 移动赋值运算符
```c++
MyString& operator=(MyString&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        other.data = nullptr;
    }
    return *this;
}
```

**关键点**
- 参数必须是 T&&，即右值引用。
- 释放旧资源，接管新资源，置空原对象资源。

## 5. 完美转发（Perfect Forwarding）
完美转发用于在模板中将参数**原封不动地转发（保留左/右值特性）**给其他函数。

实现方式：使用 `std::forward`

```c++
template<typename T>
void func(T&& arg) {
    real_func(std::forward<T>(arg));  // 保留 arg 的值类别
}
```
