#pragma once
#include <string>

class Car {
private:
    std::string model_;
    int year_;
public:
    Car();
    void setCarDetails(std::string model, int year);
    void showCarDetails() const;
};