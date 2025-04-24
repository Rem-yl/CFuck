#include <iostream>
#include <thread>

using namespace std;

void do_work(unsigned id) {
    cout << id << endl;
}

void f() {
    vector<thread> threads;
    for(unsigned i=0; i<20;++i) {
        threads.push_back(thread(do_work, i));
    }
    
    // for_each等价于
    // for(auto &t:threads) {t.join()};
    for_each(threads.begin(), threads.end(), mem_fn(&std::thread::join));
    
}

int main() {
    f();

    return 0;
}