#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    istream_iterator<int> in(cin), eof;
    ostream_iterator<int> out(cout, ","); // "," 是一个参数，表示输出值之间的分隔符

    vector<int> vec(in, eof);
    sort(vec.begin(), vec.end());
    copy(vec.begin(), vec.end(), out);
    return 0;
}