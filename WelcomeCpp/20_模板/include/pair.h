#pragma once

template<typename T>
class Pair {
    T first;
    T second;
public:
    Pair(T a, T b);
    T getMax();  // 返回较大的那个值
};