#pragma once

class Animal {
public:
    virtual void sound();
};

class Dog: public Animal {
public:
    void sound() override;
};

class Cat: public Animal {
public:
    void sound() override;
};