#pragma once

#include <cstddef>

class Buffer {
private:
    int* data;
    size_t size;

public:
    Buffer(size_t sz);
    Buffer(const Buffer& other); // 已实现拷贝构造
    Buffer(Buffer&& other);
    ~Buffer();
    
    Buffer& operator=(const Buffer& other);
    Buffer& operator=(Buffer&& other) noexcept;
};