#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class PersonInfo
{
public:
    string name;
    vector<string> phone;
};

int main()
{
    ifstream file("test.txt");
    if (!file.is_open())
    {
        cerr << "Open File Fail." << endl;
        return 0;
    }

    string line, word;
    vector<PersonInfo> persons;

    while (getline(file, line))
    {
        istringstream record(line);
        PersonInfo p;
        record >> p.name;
        while (record >> word)
        {
            p.phone.push_back(word);
        }

        persons.push_back(p);
    }

    return 0;
}