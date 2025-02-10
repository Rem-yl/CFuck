#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> read_file(string file)
{
    vector<string> res;
    ifstream f(file);
    size_t pos = 0;

    if (f.is_open())
    {
        string line;
        while (getline(f, line))
        {
            while ((pos = line.find(" ")) != string::npos)
            {
                res.push_back(line.substr(0, pos));
                line.erase(0, pos + 1);
            }
        }

        f.close();
    }

    return res;
}

template <typename T>
void print(vector<T> vec)
{
    for (const T &v : vec)
    {
        cout << v << endl;
    }
}

int main()
{
    string file = "file.txt";
    vector<string> res = read_file(file);
    print<string>(res);
    return 0;
}