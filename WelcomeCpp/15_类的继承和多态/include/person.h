#pragma once
#include <string>

class Person {
private:
    std::string name;
    std::string phone;
public:
    virtual std::string getName() const;
    virtual void speak();
};

class Student: public Person {
private:
    unsigned int grade;

public:
    unsigned int getGrade() const;
    virtual void speak() override;
};

class Teacher: public Person {
private:
    std::string subject;

public:
    std::string getSubject() const;
    virtual void speak() override;
};