#include <iostream>
#include <thread>

using namespace std;

class scoped_thread {
    thread t;
public:
    explicit scoped_thread(thread t_): t(std::move(t_)) {
        if (!t.joinable()) {
            throw std::logic_error("No thread.");
        }
    };

    ~scoped_thread() {
        t.join();
    }

    scoped_thread(scoped_thread const&)=delete;
    scoped_thread& operator=(scoped_thread const&)=delete;

};

struct func {
public: 
    int &i;
    func(int &i_): i(i_) {}
    void operator() () {
        for (unsigned j=0;j<10;++j) {
            cout << i << endl;
        }
    }
};

void f() {
    int i = 10;
    scoped_thread t((thread(func(i))));
    cout << "hello, rem!" << endl;
}

int main() {
    f();

    return 0;
}