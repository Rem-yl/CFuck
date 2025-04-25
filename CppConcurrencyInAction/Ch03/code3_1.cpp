#include <list>
#include <mutex>
#include <algorithm>
#include <iostream>

using namespace std;

list<int> some_list;
mutex some_mutex;


void add_to_list(int value) {
    lock_guard<mutex> guard(some_mutex);   // 当 guard 构造时加锁，析构时自动释放
    some_list.push_back(value);
}

bool list_contains(int value_to_find) {
    lock_guard<mutex> guard(some_mutex);

    return find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}

int main() {
    vector<int> v = {1,2,3,4,5};
    for (auto &i :v) {
        add_to_list(i);
    }

    cout << list_contains(2) << endl;

    return 0;
}
