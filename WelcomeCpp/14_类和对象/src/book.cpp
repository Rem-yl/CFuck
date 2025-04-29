#include "book.h"
#include <string>
#include <iostream>

Book::Book(std::string isbn_, float value_) {
    isbn = isbn_;
    value = value_;
    std::cout << "Book created" << std::endl;
}

Book::Book():Book("", 0.0) {};

Book::~Book() {
    std::cout << "Book deleted" << std::endl;
}