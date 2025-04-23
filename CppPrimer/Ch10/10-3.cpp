#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<double> vec = {0, 1.0, 2.0, 3.0, 4.0, 5.5, 6.6};
    vector<double> vec1 = {0, 1.0, 2.0, 3.0, 4.0, 5.5};

    auto res = accumulate(vec.begin(), vec.end(), 0.0);

    auto res1 = equal(vec.begin(), vec.end(), vec1.begin());

    cout << "res: " << res << endl;
    cout << "res1: " << res1 << endl;
    return 0;
}