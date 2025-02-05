/* 6.5 输出实参绝对值*/
#include <iostream>

using namespace std;

int abs(int num)
{
    return num > 0 ? num : -num;
}

int main()
{
    int input;
    cout << "Please Input Number: ";

    cin >> input;

    int res = abs(input);

    cout << "abs(" << input << ") = " << res << endl;
}