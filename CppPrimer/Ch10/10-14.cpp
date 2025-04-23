#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    auto f = [](int a, int b) -> int
    { return a + b; };

    int res = f(1, 2);
    cout << "res: " << res << endl;
    return 0;
}