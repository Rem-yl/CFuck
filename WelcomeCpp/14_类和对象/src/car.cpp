#include "car.h"
#include <string>
#include <iostream>

Car::Car(): model_(""), year_(0) {};

void Car::setCarDetails(std::string model, int year) {
    model_ = model;
    year_ = year;
}

void Car::showCarDetails() const {
    std::cout << "model: " << model_ << ", " << "year: " << year_ << std::endl;
}