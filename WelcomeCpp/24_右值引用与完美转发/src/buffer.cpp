#include "buffer.h"

#include <algorithm>

Buffer::Buffer(size_t sz)
    : size(sz)
    , data(new int[sz]) {};

Buffer::Buffer(const Buffer &other) {
    size = other.size;
    data = new int[size];
    std::copy(other.data, other.data + size, data);
}

Buffer::Buffer(Buffer &&other) {
    size = other.size;
    data = other.data;
    other.data = nullptr;
    other.size = 0;
}

Buffer::~Buffer() {
    delete[] data;
    data = nullptr;
}

Buffer &Buffer::operator=(const Buffer &other) {
    if (this == &other) {
        return *this;
    }

    delete[] data;
    size = other.size;
    data = new int[size];
    std::copy(other.data, other.data + size, data);

    return *this;
}

Buffer &Buffer::operator=(Buffer &&other) noexcept {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = other.data;

        other.data = nullptr;
        other.size = 0;
    }

    return *this;
}
