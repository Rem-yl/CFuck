#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> vec)
{
    for (const int& v:vec)
    {
        cout << v << " ";
    }

    cout << endl;
}
int main()
{
    vector<int> vec(10, 0);
    vector<int> vec1(10);
    print(vec1);
    return 0;
}