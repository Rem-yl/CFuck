#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    string name;
    string addr;

    Person(string name, string addr) : name(name), addr(addr) {}
    string get_name() const // const 是函数修饰符, 表示函数是常量成员函数, 不会修改类的成员变量
    {   
        return name;
    }

    string get_addr() const
    {
        return addr;
    }
};

int main()
{
    Person p("rem", "hello");
    string name = p.get_name();
    cout << "name: " << name << endl;
    return 0;
}