# C++并发编程实战
## 资料
[原书](https://github.com/ZhouZhaoJi/Library/blob/master/Programming/C++%E5%B9%B6%E5%8F%91%E7%BC%96%E7%A8%8B%E5%AE%9E%E6%88%98.pdf)

## Ch02
### Most Vexing Parse问题
---
```c++
std::thread t(BackgroundTask());
```
上面代码存在“Most Vexing Parse”（最烦人的解析）问题，它指的是一个声明语句在语法上看起来像是一个对象定义，但实际上被解析成了一个函数声明，从而产生出乎意料的行为。

你想表达的意思是：

- 创建一个 `BackgroundTask` 的临时对象，并用它来构造一个 `std::thread` 对象 t。

但是编译器看到的是：

- 声明一个函数 `t`，它接受一个参数（类型是返回 `BackgroundTask` 的函数指针），并返回一个`std::thread`。

这就产生了歧义——而且编译器总是偏向“函数声明”的解析方式，导致你以为你定义了一个对象，实际上定义的是一个函数声明，这就是 Most Vexing Parse。

使用以下方法可以解决这个问题:

```c++
std::thread t(（BackgroundTask()）);    // 多组括号消除歧义
std::thread t{BackgroundTask()};    //  统一初始化
std::thread t([]{
    hello();
    hello_rem();
})  // lambda表达式
```

### 向线程函数传递参数
---
默认参数要拷贝到线程独立内存中,即使参数是引用的形式,也可以在新线程中进行访问。

**❎ 问题代码**
```c++
void f(int i,std::string const& s); 
void oops(int some_param) {   
    char buffer[1024];  
    sprintf(buffer, "%i",some_param);   std::thread t(f,3,buffer); 
    t.detach(); 
}
```

问题解释    
1.	buffer 是局部变量，它的生命周期只存在于 oops 函数内部。

2.	`std::thread t(f, 3, buffer)` 中的 buffer 被作为 `std::string const& s` 传给线程函数 f。

std::thread 会将其参数复制或移动到新线程的上下文中。
但 buffer 是 char* 类型，不是 std::string，所以在这行代码中：
```c++
std::thread t(f, 3, buffer);
```

实际等效于创建了一个临时 std::string(buffer)，然后再传给 f 的引用参数。

3.	但由于传的是 std::string const&，它不会拷贝，而是保留了对临时 std::string 的引用。
4.	临时 std::string 的生命周期 只保证活到这一行结束。但是线程是异步执行的，可能在临时对象销毁后才运行 f，这就导致了 悬空引用。

**✅ 正确代码**
```c++
void f(int i,std::string const& s); 
void not oops(int some_param) {   
    char buffer[1024];  
    sprintf(buffer, "%i",some_param);   std::thread t(f,3,std::string(buffer));     //在创建线程时显式构造一个 std::string, 让它的生命周期和线程绑定
    t.detach(); 
}
```

**❎ 传递非常量引用时的问题**
```c++
void update_data_for_widget(widget_id w,widget_data& data); // 函数希望接收引用的参数data
void oops_again(widget_id w) {   
    widget_data data;   
    std::thread t(update_data_for_widget,w,data); // 这里其实是复制了一份data到线程中
    t.join();  
    process_widget_data(data);
}
```
这里存在的问题是:   
- std::thread 的构造函数会尝试拷贝每个参数（除非用 std::ref 明确表示引用）。
- 你以为 data 是通过引用传进去的，但其实是传值了（拷贝了一份 data），然后这个拷贝会被传给 update_data_for_widget。
- 可怕的是：update_data_for_widget 的参数声明是 widget_data&，它会引用这个线程上下文中的临时 data 副本，但主线程继续用的是原始 data 对象。
- 所以，线程中修改的数据和主线程里的 data 是 两个不同的对象，process_widget_data(data); 得到的是未更新的版本。

**✅ 正确的做法**
```c++
std::thread t(update_data_for_widget, w, std::ref(data));
```