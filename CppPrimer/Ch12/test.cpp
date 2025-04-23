#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main()
{
    shared_ptr<int> p(new int(42));
    int *q = p.get();
    shared_ptr<int>(q);
    int foo = *p;
}