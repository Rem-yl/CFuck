#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

template <typename T>
void print_list(list<T> lst)
{
    for (const T& l:lst)
    {
        cout << l << " ";
    }

    cout << endl;
}

int main()
{
    istream_iterator<int> in(cin), eof;

    cout << accumulate(in, eof, 0) << endl;
}