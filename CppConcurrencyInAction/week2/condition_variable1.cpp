#include <iostream>
#include <thread>
#include <condition_variable>

class A {
private:
    std::condition_variable cv_;
    std::mutex m_;
    bool step1_done = false;
    bool step2_done = false;

public:
    void step1() {
        {
            std::lock_guard<std::mutex> l(m_);
            step1_done = true;
        }

        std::cout << "step1 done." << std::endl;
        
        cv_.notify_one(); // 通知 step2
    }

    void step2() {
        std::unique_lock<std::mutex> l(m_);
        std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // 等待2秒
        cv_.wait(l, [this] {return step1_done;});  // 等待 step1 完成
        step2_done = true;
        std::cout << "step2 done." << std::endl;
        
        cv_.notify_one();  // 通知 step3
    }

    void step3() {
        std::unique_lock<std::mutex> l(m_);
        cv_.wait(l, [this] {return step2_done;});  // 等待 step2 完成
        std::cout << "step3 done." << std::endl;
    }
};

int main() {
    A a;
    std::thread t1(&A::step1, &a);
    std::thread t2(&A::step2, &a);
    std::thread t3(&A::step3, &a);

    t1.join();
    t2.join();
    t3.join();
}