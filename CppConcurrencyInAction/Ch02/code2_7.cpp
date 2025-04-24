#include <iostream>
#include <thread>

using namespace std;

class joinging_thread {
    thread t;
public:
    bool joinable() const noexcept {
        return t.joinable();
    }
    void join() {
        t.join();
    }

    void detach() {
        t.detach();
    }

    joinging_thread() noexcept=default; // 如果真的抛出了异常，会触发 std::terminate() 直接终止程序。

    template<typename Callable, typename ... Args>
    explicit joinging_thread(Callable&& func, Args&& ... args):
        t(std::forward<Callable>(func), std::forward<Args>(args)...)    // &&配合模板类进行完美转发, 万能引用
        {}
    explicit joinging_thread(thread t_) noexcept: t(std::move(t_)) {}

    // 移动构造函数
    joinging_thread(joinging_thread&& other) noexcept: t(std::move(other.t)) {} // &&表示函数需要传入 右值引用 的对象

    joinging_thread& operator=(joinging_thread&& other) noexcept {
        if (joinable()) {
            join();
        }

        t = std::move(other.t);
        return *this;
    }

    joinging_thread& operator=(thread other) noexcept {
        if(joinable()) {
            join();
        }

        t = std::move(other);
        return *this;
    }

    void swap(joinging_thread& other) noexcept {
        t.swap(other.t);
    }

    thread::id get_id() const noexcept {
        return t.get_id();
    }

    thread& as_thread() noexcept {
        return t;
    }

    const thread& as_thread() const noexcept {
        return t;
    }
};