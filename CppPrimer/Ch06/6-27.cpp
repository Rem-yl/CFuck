#include <iostream>
#include <string>

using namespace std;

int sum(initializer_list<int> list)
{
    int res = 0;
    for (auto begin = list.begin(); begin != list.end(); ++begin)
    {
        res += *begin;
    }

    return res;
}

int main()
{
    int res = sum({1,2,3,4,5});
    cout << "res: " << res << endl;
    return 0;
}