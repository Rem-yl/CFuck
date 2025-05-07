#include "CommandRegistry.h"
#include <iostream>
#include <vector>

template <typename T>
bool ascending(T a, T b) {
    return a < b;
}

template <typename T>
bool descending(T a, T b) {
    return a > b;
}

template <typename T>
void sort(std::vector<T> &data, bool (*cmp)(T, T)) {
    auto size = data.size();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (!cmp(data[j], data[j + 1])) {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

template <typename T>
void printVector(std::vector<T> data) {
    for (auto &v : data) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void test1() {
    std::vector<int> data = {1, 4, 2, 6, 7, 2, 43, 56, 2342};
    sort<int>(data, ascending<int>);
    printVector<int>(data);
    sort<int>(data, descending<int>);
    printVector<int>(data);
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

void test2() {
    CommandRegistry registry;
    registry.registerCommand("add", add);
    registry.registerCommand("sub", sub);

    std::cout << registry.execute("add", 5, 3) << std::endl;  
    std::cout << registry.execute("sub", 5, 0) << std::endl;  
}

int main() {
    // test1();
    test2();
    return 0;
}