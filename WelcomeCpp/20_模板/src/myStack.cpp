#include "myStack.h"

#include <vector>

template<typename T>
MyStack<T>::MyStack():top(0) {};

template<typename T>
void MyStack<T>::push(T value) {
    data.push_back(value);
}

template<typename T>
void MyStack<T>::pop() {
    if (!data.empty()) {
        data.pop_back();
    }
}

template<typename T>
T MyStack<T>::peek() {
    if (!data.empty()) {
        return data.back();
    }
}

template<typename T>
bool MyStack<T>::isEmpty() {
    return data.empty();
}
