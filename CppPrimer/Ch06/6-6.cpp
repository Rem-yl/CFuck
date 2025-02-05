/* 6.6 说明形参、局部变量以及局部静态变量的区别 */

#include <iostream>

using namespace std;

int fact(int num)   // num是形参
{
    static int cnt = 0;  // 统计函数被调用了几次
    ++cnt;
    cout << "fact function has been called: " << cnt << endl;
    
    if (num <= 1)
    {
        return num;
    }
    else
    {
        return num * fact(num-1);
    }
    

}

int main()
{
    int input;
    cout << "Please Input Number: ";

    cin >> input;

    int res = fact(input);

    cout << "fact(" << input << ") = " << res << endl;
}