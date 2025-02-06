#include <iostream>

using namespace std;

int& test()
{
    int res = 10;
    return res;
}

int main()
{
    int res = test();
    cout << res << endl;
    return 0;
}