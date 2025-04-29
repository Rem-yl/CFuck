#include "person.h"

#include <string>
#include <iostream>

std::string Person::getName() const {
    return name;
}

void Person::speak() {
    std::cout << "Person speak" << std::endl;
}

void Student::speak()  {
    std::cout << "Student speak" << std::endl;
}

unsigned int Student::getGrade() const {
    return grade;
}

std::string Teacher::getSubject() const {
    return subject;
}

void Teacher::speak() {
    std::cout << "Teacher speak" << std::endl;
}