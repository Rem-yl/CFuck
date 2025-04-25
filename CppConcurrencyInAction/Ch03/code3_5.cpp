#include <exception> 
#include <memory> 
#include <mutex> 
#include <stack>

using namespace std;

struct empty_stack: std::exception {
    const char* what() const throw() {
        return "empty stack!";
    };
};

template<typename T>
class threadsafe_stack {
private:
    stack<T> data;
    mutable mutex m;

public:
    threadsafe_stack(): data(stack<T>()) {}

    threadsafe_stack(const threadsafe_stack& other) {
        lock_guard<mutex> lock(other.m);
        data = other.data;
    }

    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value) {
        lock_guard<mutex> lock(m);
        data.push(new_value);
    }

    shared_ptr<T> pop() {
        lock_guard<mutex> lock(m);
        if(data.empty()) throw empty_stack();
        // 创建一个 shared_ptr<T> 智能指针 res，指向栈顶元素的副本（注意不是直接返回栈顶的指针，而是拷贝一份并放在堆上）
        shared_ptr<T> const res(make_shared<T>(data.top()));
        data.pop();

        return res;
    }

    bool empty() const  {   // 常量成员函数, 不改变类的值
        lock_guard<mutex> lock(m);
        return data.empty();
    }
};