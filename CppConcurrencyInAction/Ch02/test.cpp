#include <iostream>
#include <thread>

using namespace std;

void hello() {
    cout << "hello, world!" << endl;
}

void hello_rem() {
    cout << "hello, rem!" << endl;
}

int main() {
    thread t1(hello);
    thread t2 = std::move(t1);
    t1 = thread(hello_rem);
    thread t3;
    t3 = std::move(t2);
    t1 = std::move(t3);

    return 0;
}
