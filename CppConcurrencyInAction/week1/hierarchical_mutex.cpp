#include <iostream>
#include <mutex>
#include <stdexcept>

class HierarchicalMutex {
private:
    std::mutex m;
    const int cur_hierarchy_;
    int pre_hierarchy_;
    static thread_local int thread_hierarchy_;  // 局部作用域+全局生命周期

    void valid_hierarchy() {
        if(thread_hierarchy_ <= cur_hierarchy_) {
            throw std::logic_error("valid_hierarchy error.");
        }
    }

    void update_hierarchy() {
        pre_hierarchy_ = thread_hierarchy_;
        thread_hierarchy_ = cur_hierarchy_;
    }

public:
    explicit HierarchicalMutex(int cur_hierarchy, int pre_hierarchy=0):
        cur_hierarchy_(cur_hierarchy), pre_hierarchy_(pre_hierarchy) {} 
        
    void lock() {
        valid_hierarchy();
        m.lock();
        update_hierarchy();
    }

    void unlock() {
        if(thread_hierarchy_ != cur_hierarchy_) {
            throw std::logic_error("unlock error.");
        }

        thread_hierarchy_ = pre_hierarchy_;
        m.unlock();
    }
};

thread_local int HierarchicalMutex::thread_hierarchy_(INT_MAX);

void HighLockFunc() {
    HierarchicalMutex HighMutex(100);
    std::lock_guard<HierarchicalMutex> l(HighMutex);
    std::cout << "HighLockFunc" << std::endl;
}

void LowLockFunc() {
    HierarchicalMutex LowMutex(0);
    std::lock_guard<HierarchicalMutex> l(LowMutex);
    std::cout << "LowLockFunc" << std::endl;
}

void f() {
    HierarchicalMutex MidMutex(50);
    std::lock_guard<HierarchicalMutex> l(MidMutex); //调用 MidMutex.lock(), thread_hierarchy_=50
    std::cout << "f()" << std::endl;
    HighLockFunc(); // 调用 HighMutex.lock()时报错
}

int main() {
    f();
    return 0;
}