# 21. 异常
## 1. 异常的概念
- 异常（Exception） 是程序运行时出现的错误情况，如除以零、越界访问、文件打开失败等。
- C++ 通过 try-catch-throw 机制来捕获和处理异常，使程序更加健壮。

```c++
try {
    // 可能抛出异常的代码
    throw 异常对象;
}
catch (异常类型 参数名) {
    // 异常处理代码
}
```

**catch 块**
- 可以有多个 catch 语句处理不同类型异常
- 顺序很重要，派生类异常应放在前面
- 使用 catch (...) 捕获所有类型的异常

## 2. 标准异常类
| 类名 | 描述 | 
| :--- | :--- |  
| std::exception | 所有标准异常的基类 | 
| std::logic_error | 逻辑错误 | 
| std::runtime_error | 运行时错误 | 
| std::out_of_range | 越界 |
| std::invalid_argument | 无效参数 |
| std::bad_alloc | 内存分配失败（如 new）|

**自定义异常类**
```c++
class MyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "自定义异常发生";
    }
};
```