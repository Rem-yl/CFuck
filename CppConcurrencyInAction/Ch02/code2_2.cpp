#include <iostream>
#include <thread>

using namespace std;

void print(int &i) {
    cout << i << endl;
}

struct func {
public: 
    int &i;
    func(int &i_): i(i_) {}
    void operator() () {
        for (unsigned j=0;j<100;++j) {
            print(i);
        }
    }
};

void f() {
    int some_local_state = 0;
    func my_func(some_local_state);
    thread t(my_func);

    // 使用 try/catch 确保访问本地状态的线程退出后, 函数才会结束
    try {
        cout << 10 << endl;
    }
    catch(...) {
        t.join();
        throw;
    }

    t.join();
}

int main() {
    f();
}