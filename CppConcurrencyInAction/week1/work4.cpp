// 简单演示死锁
#include <iostream>
#include <mutex>
#include <thread>

std::mutex m1, m2;

void thread1() {
    std::lock_guard<std::mutex> l1(m1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> l2(m2);

    std::cout << "thread1 done." << std::endl;
}

void thread2() {
    std::lock_guard<std::mutex> l2(m2);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> l1(m1);

    std::cout << "thread2 done." << std::endl;
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}