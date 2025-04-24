#include <iostream>
#include <thread>

using namespace std;

void hello() {
    cout << "hello, world!" << endl;
}

void hello_rem() {
    cout << "hello, rem!" << endl;
}

class BackgroundTask {
public:
    void operator()() const {
        hello();
        hello_rem();
    }
};


int main() {
    thread t(BackgroundTask());
    t.join();
    return 0;
}