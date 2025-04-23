#include <iostream>
#include <vector>
#include <list>
#include <algorithm> 

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
    vector<int> vec = {1, 1, 2, 3, 3, 4, 4, 5, 6, 7, 8, 8, 8};
    list<int> lst;

    unique_copy(vec.begin(), vec.end(), back_inserter(lst));

    print_list<int>(lst);
    return 0;
}