# 22.函数指针
## 1. 什么是函数指针
函数指针是指向函数的指针变量，它可以像函数一样被调用。
```c++
返回类型 (*指针变量名)(参数类型列表);
```

```c++
int add(int a, int b);
int (*funcPtr)(int, int) = add;
```

## 2. 函数指针的使用
**1. 定义函数指针**
```c++
int max(int a, int b) {
    return (a>b) ? a : b;
}

int (*p)(int, int);
p = max;
```

**2. 调用函数指针**
```c++
int res = p(10, 20);
int res2 = (*p)(10, 20);
```

## 3. 函数指针作为参数
可以将函数指针作为参数传递：
```c++
void process(int a, int b, int (*op)(int, int)) {
    std::cout << "Result: " << op(a, b) << std::endl;
}
```
调用: 
```c++
int add(int x, int y) { return x + y; }
process(3, 4, add);
```

## 4. 函数指针数组
用于实现策略选择或回调机制：
```c++
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int (*ops[2])(int, int) = { add, sub };

int result = ops[0](3, 4);  // 调用 add
```

## 5. 函数指针与 typedef / using
提升可读性：
```c++
typedef int (*FuncPtr)(int, int);
using FuncPtr2 = int(*)(int, int);

void run(FuncPtr f) { std::cout << f(1, 2); }
```


## 6. 函数指针 vs 成员函数指针
成员函数指针与普通函数指针不同：
```c++
class A {
public:
    void show() { std::cout << "A::show()" << std::endl; }
};

void test() {
    A a;
    void (A::*p)() = &A::show;  // 成员函数指针
    (a.*p)();                   // 调用
}
```