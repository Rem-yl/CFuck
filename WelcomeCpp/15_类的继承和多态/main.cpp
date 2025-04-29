#include "animal.h"
#include "person.h"

#include <iostream>
#include <string>

void makeSound(Animal* animal) {
    animal->sound();
}

void personSpeak(Person* person) {
    person->speak();
}

void test1() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    makeSound(dog);
    makeSound(cat);
    delete dog;
    delete cat;
}

void test2() {
    Person* p1 = new Person();
    Person* p2 = new Student();
    Person* p3 = new Teacher();

    personSpeak(p1);
    personSpeak(p2);
    personSpeak(p3);
    
    delete p1;
    delete p2;
    delete p3;
}

int main() {
    // test1();
    test2();

    return 0;
}