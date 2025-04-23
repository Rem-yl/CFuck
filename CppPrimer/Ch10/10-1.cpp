#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    vector<int> vec = {0, 0, 1, 2, 32, 1, 3, 0};
    auto res = count(vec.begin(), vec.end(), 1);

    cout << "res: " << res << endl;
}