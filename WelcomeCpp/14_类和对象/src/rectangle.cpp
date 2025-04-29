#include "rectangle.h"
#include <iostream>
#include <string>

int Rectangle::total = 0;

Rectangle::Rectangle(float weight_, float height_):
    weight(weight_), height(height_)    
{   
    total++;
    std::cout << "Rectangle Created" << std::endl;
}

Rectangle::Rectangle(): Rectangle(0.0, 0.0) {}

Rectangle::Rectangle(const Rectangle& other) {
    total++;
    weight = other.weight;
    height = other.height;
    std::cout << "Rectangle Created" << std::endl;
}

Rectangle::~Rectangle() {
    total--;
    std::cout << "Rectangle Deleted" << std::endl;
}

int Rectangle::getTotal(){
    return total;
}