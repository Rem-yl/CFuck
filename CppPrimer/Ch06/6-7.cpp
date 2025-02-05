#include <iostream>

using namespace std;
int func()
{
    static int res = -1;
    ++res;
    return res;
}

int main()
{
    int res;
    res = func();
    cout << res << endl;
    res = func();
    cout << res << endl;
}