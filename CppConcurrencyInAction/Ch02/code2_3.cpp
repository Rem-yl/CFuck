#include <iostream>
#include <thread>

using namespace std;

struct func {
public: 
    int &i;
    func(int &i_): i(i_) {}
    void operator() () {
        for (unsigned j=0;j<100;++j) {
            cout << i << endl;
        }
    }
};

class thread_guard {
    thread& t;
public:
    explicit thread_guard(thread& t_): t(t_) {};
    ~thread_guard() {
        // 析构函数, 当对象被销毁时加入线程
        if (t.joinable()) {
            t.join();
        }
    }

    thread_guard(thread_guard const&)=delete;   // 禁止拷贝构造
    thread_guard& operator=(thread_guard const&)=delete; //禁止赋值构造
};

void f() {
    int i = 0;
    func my_func(i);
    thread t(my_func);
    thread_guard g(t);  // 对象g被销毁时, 析构函数会将线程加入原始线程中, 即使主线程发生了异常
    cout << "hello, world" << endl;
}   // 线程运行到这里时要被逆向销毁

int main() {
    f();
    return 0;
}