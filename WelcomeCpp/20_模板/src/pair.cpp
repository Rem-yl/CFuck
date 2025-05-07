#include "pair.h"

template<typename T>
Pair<T>::Pair(T a, T b):first(a), second(b) {};

template<typename T>
T Pair<T>::getMax() {
    return std::max<T>(first, second);
}