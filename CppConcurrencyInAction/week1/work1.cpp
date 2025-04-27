#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

static int n = 0;
const int max_n = 10;
std::mutex m;

void print_odd() {
    while (true) {
        {
            std::lock_guard<std::mutex> lock(m);
            if (n >= max_n) {
                break;
            }
            if (n % 2 == 1) {
                std::cout << "odd: " << n << std::endl;
                ++n;
            }
        }
    }
}

void print_even() {
    while (true) {
        {
            std::lock_guard<std::mutex> lock(m);
            if (n >= max_n) {
                break;
            }
            if (n % 2 == 0) {
                std::cout << "even: " << n << std::endl;
                ++n;
            }
            
        }
    }
}

int main() {
    std::thread t1(print_odd);
    std::thread t2(print_even);

    t1.join();
    t2.join();

    return 0;
}