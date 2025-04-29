#include "car.h"
#include "book.h"
#include "rectangle.h"

#include <iostream>
#include <memory>

void test1() {
    std::shared_ptr<Car> c = std::make_shared<Car>();
    c->setCarDetails("rem", 1998);
    c->showCarDetails();
}

void test2() {
    std::shared_ptr<Book> b = std::make_shared<Book>("123", 10.5);
}

void test3() {
    Rectangle* r1 = new Rectangle(0.5, 0.4);
    Rectangle* r2 = new Rectangle();
    Rectangle* r3 = new Rectangle(*r2);

    std::cout << Rectangle::getTotal() << std::endl;
    delete r1;
    std::cout << Rectangle::getTotal() << std::endl;
    delete r3;
    std::cout << Rectangle::getTotal() << std::endl;
    delete r2;
    std::cout << Rectangle::getTotal() << std::endl;
    
}


int main() {
    // test1();
    // test2();
    test3();

    return 0;
}