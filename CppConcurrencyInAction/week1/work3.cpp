#include <iostream>
#include <thread>
#include <mutex>

unsigned int n = 0;

void f() {
    while(n < 20){
        n++;
        std::cout << n << std::endl;
    }
}

int main() {
    std::thread t1(f);
    std::thread t2(f);
    std::thread t3(f);

    t1.join();
    t2.join();
    t3.join();
}