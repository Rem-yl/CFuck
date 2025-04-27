#include <iostream>
#include <thread>
#include <mutex>

class Counter {
private:
    std::mutex m_;
    unsigned int count = 0;
public:
    
    void add() {
        std::lock_guard<std::mutex> l(m_);
        count++;
    }

    unsigned int get_count() {
        std::lock_guard<std::mutex> l(m_);
        return count;
    }   
};

static Counter c;

void f() {
    while (c.get_count() < 10) {
        c.add();
        std::cout << c.get_count() << std::endl;
    }
}

int main() {
    std::thread t1(f);
    std::thread t2(f);

    t1.join();
    t2.join();
}