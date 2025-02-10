#include <iostream>
#include <sstream>
#include <string>


using namespace std;

istream& func(istream& is)
{
    string line;
    while (getline(is, line))
    {
        cout << line << endl;
    }
    is.clear();

    return is;
}

int main()
{
    string input = "hello, world";
    istringstream iss(input);

    istream& is = func(iss);
    if (is.good())
    {
        cout << "reset done." << endl;
    }

    return 0;
}