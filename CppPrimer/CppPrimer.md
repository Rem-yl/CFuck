# C++ Primer 中文第五版

## Ch06 函数

**6.1 实参和形参的区别是什么？**
函数的实参是形参的初始值，形参在函数内部是局部变量，而实参是函数调用时提供给函数的值。

形参是一种自动对象，函数开始时为形参申请存储空间，函数一旦终止，形参也就被销毁。

**局部静态对象**：直到程序终止才会被销毁。

```c++
size_t count_calls()
{
    static size_t ctr = 0;
    return ++ctr;
}

int main()
{
    for (size_t i=0; i <=10; ++i)
    {
        cout << count_calls() << endl;
    }
}
```

我们可以使用非常量来初始化一个底层 const 对象，但是反过来不行。因此我们尽量使用常量引用。当输入是字面值、常量或者不应该改变的值时，形参应该使用常量引用。

**main 函数处理命令行选项**

```c++
int main(int argc, char *argv[])
```

- `argc` 是一个整数，代表命令行参数的数量，包括程序名本身。
- `argv` 是一个字符指针数组，存储了命令行参数的值，每个元素都是一个字符串。

当使用 argv 中的实参时,一定要记得可选的实参从 argv[1]开始;argv[0]保存程序的名字,而非用户输入

**可变数量的形参**
使用`initializer_list<T>`实现传递可变的形参个数

```c++
int sum(initializer_list<int> list)
{
    int res = 0;
    for (auto begin = list.begin(); begin != list.end(); ++begin)
    {
        res += *begin;
    }

    return res;
}

int main()
{
    int res = sum({1,2,3,4,5});
    cout << "res: " << res << endl;
    return 0;
}
```

**引用返回左值**
`左值`可以理解成在运算符的左边，即可以赋值
函数的返回类型决定函数调用是否是左值，调用一个返回引用的函数得到左值,其他返回类型得到右值

**函数指针**

```c++
bool (*pf)(const string &, const string &);
```

`pf`是指向函数的指针

## Ch07 类

**常量成员函数**

```c++
string get_name() const // const 是函数修饰符, 表示函数是常量成员函数, 不会修改类的成员变量
{
    // name = "res";  // 报错
    return name;
}
```

**struct 和 class 之间的区别**
如果我们使用 struct 关键字,则定义在第一个访问说明符之前的成员是 public 的;相反,如果我们使用 class 关键字,则这些成员是 private 的。

**友元**
如果类想把一个函数作为它的友元,只需要增加一条以`friend`关键字开始的函数声明语句即可

初始化与赋值区别：构造函数初始值列表直接初始化数据成员，而在构造函数体中赋值是先默认初始化再赋值，对于 const、引用或无默认构造函数的类类型成员，必须使用构造函数初始值列表初始化。

```c++
class ConstRef{
    public:
        ConstRef (int ii);
    private:
        int i;
        const int ci;
        int &ri;
};

//错误:ci和ri必须被初始化
ConstRef::ConstRef (int ii) {//赋值:
    i=ii; //正确
    ci=ii; //错误:不能给const赋值
    ri=i; //错误:ri没被初始化
}

//正确:显式地初始化引用和const成员
ConstRef::ConstRef(int ii):i(ii),ci(ii),ri(i){}
```

在很多类中,初始化和赋值的区别事关底层效率问题:前者直接初始化数据成员, 后者则先初始化再赋值。

**成员的初始化顺序与它们在类定义中的出现顺序一致:第一个成员先被初始化,然后第二个,以此类推。构造函数初始值列表中初始值的前后位置关系不会影响实际的初始化顺序。**
```c++
class Example {
private:
    // 成员声明顺序：a 先声明，b 后声明
    int a;
    int b;

public:
    // 构造函数，错误示例：初始值顺序与声明顺序不一致且用后声明的成员初始化先声明的成员
    Example(int value) : b(value), a(b) {
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }

    // 构造函数，正确示例：初始值顺序与声明顺序一致且避免用成员初始化其他成员
    Example(int value1, int value2) : a(value1), b(value2) {
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }
};
```

## Ch08 IO库
- `iostream` 处理控制台IO
- `fstream` 处理命名文件IO
- `stringstream` 完成内存string的IO