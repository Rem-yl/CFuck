#include <iostream>
#include <string>
using namespace std;

void print(int arr[])
{
    cout << arr[2] << endl;
}

int main()
{
    int arr[2] = {0,0};

    print(arr);
}