#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template<typename T>
void print_list(list<T> lst)
{
    for (const T &l : lst)
    {
        cout << l << " ";
    }

    cout << endl;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lst1, lst2, lst3;

    copy(vec.begin(), vec.end(), inserter(lst1, lst1.begin()));
    copy(vec.begin(), vec.end(), back_inserter(lst1));
    copy(vec.begin(), vec.end(), front_inserter(lst1));

    print_list<int>(lst1);
    print_list<int>(lst2);
    print_list<int>(lst3);
}