/* 6.4 输入一个整数，生成阶乘*/

#include <iostream>

using namespace std;

int fact(int num)
{
    int res = 1;
    while (num >= 1)
    {
        res *= num;
        --num;
    }

    return res;
}

int main()
{
    int input;
    cout << "Please Input Number: ";

    cin >> input;

    int res = fact(input);

    cout << "fact(" << input << ") = " << res << endl;
}