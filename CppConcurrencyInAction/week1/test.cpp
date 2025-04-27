#include <iostream>
#include <thread>
#include <mutex>

static thread_local int local_count = 0;
std::mutex cout_mutex;  // 为了避免cout混乱，添加一个锁

void f() {
    local_count++;

    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "thread " << std::this_thread::get_id() << " count: " << local_count << std::endl;
    }

    std::cout << "done," << std::endl;
}

int main() {
    std::thread t1(f);
    std::thread t2(f);
    t1.join();
    t2.join();
}