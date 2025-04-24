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

void oops() {
    int some_local_state = 0;
    func my_func(some_local_state);
    thread my_thread(my_func);
    my_thread.detach();
}
int main() {
    oops();
    return 0;
}
