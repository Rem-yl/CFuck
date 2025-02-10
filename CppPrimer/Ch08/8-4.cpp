#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> read_file(string file)
{   
    vector<string> res;
    ifstream f(file);

    if (f.is_open())
    {
        string line;
        while(getline(f, line))
        {
            res.push_back(line);
        }

        f.close();
    }

    return res;
}

template<typename T>
void print(vector<T> vec)
{
    for (const T& v: vec)
    {
        cout << v << " ";
    }
    cout << endl;
}


int main()
{
    string file = "file.txt";
    vector<string> res = read_file(file);
    print<string>(res);
    return 0;
}