#pragma once
#include <string>

class Book {
private:
    std::string isbn;
    float value;

public:
    Book();
    Book(std::string isbn_, float value_);
    ~Book();
};