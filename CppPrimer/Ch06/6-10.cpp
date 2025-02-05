#include <iostream>

using namespace std;

void exchange(int* num1, int* num2)
{
    int tmp;
    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;
}

int main()
{   
    int num1 = 1;
    int num2 = 2;
    exchange(&num1, &num2);

    cout << "num1: " << num1 << ", " << "num2: " << num2 << endl;
    return 0;
}