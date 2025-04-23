#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{   
    vector<string> vec;
    ifstream file("file.txt");
    istream_iterator<string> in(file), eof;

    while (in != eof)
    {
        vec.push_back(*in++);
    }

    for (const auto& v:vec)
    {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}