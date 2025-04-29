#pragma once
#include <string>

class Rectangle {
private:
    static int total;
    float weight;
    float height;

public:  
    Rectangle();
    Rectangle(float weight_, float height_);
    Rectangle(const Rectangle& other);
    ~Rectangle();

public:
    static int getTotal();
};