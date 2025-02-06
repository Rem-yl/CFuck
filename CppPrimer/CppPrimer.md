# C++ Primer中文第五版
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

我们可以使用非常量来初始化一个底层const对象，但是反过来不行。因此我们尽量使用常量引用。当输入是字面值、常量或者不应该改变的值时，形参应该使用常量引用。

**main函数处理命令行选项**
```c++
int main(int argc, char *argv[])
```
- `argc` 是一个整数，代表命令行参数的数量，包括程序名本身。
- `argv` 是一个字符指针数组，存储了命令行参数的值，每个元素都是一个字符串。

当使用argv中的实参时,一定要记得可选的实参从 argv[1]开始;argv[0]保存程序的名字,而非用户输入

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