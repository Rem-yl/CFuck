#include <iostream>
#include <thread>

void HelloConcurrent() {
    std::cout << "hello, concurrent world!" << std:: endl;
}

void hello() {
    std::cout << "Hello, world!" << std::endl;
}

int main() {

    hello();

    std::thread t(HelloConcurrent);
    t.join();

    return 0;
}
