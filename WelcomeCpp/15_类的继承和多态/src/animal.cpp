#include "animal.h"
#include <iostream>
#include <string>

void Animal::sound() {
    std::cout << "Animal sound" << std::endl;
}

void Dog::sound() {
    std::cout << "Dog sound" << std::endl;
}

void Cat::sound() {
    std::cout << "Cat sound" << std::endl;
}