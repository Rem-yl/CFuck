#pragma once

#include <vector>

template<typename T>
class MyStack {
private:
    std::vector<T> data;
    int top;
public:
    MyStack();
    void push(T value);
    void pop();
    T peek();
    bool isEmpty();
};