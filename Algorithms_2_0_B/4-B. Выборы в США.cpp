#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    map<string, int> mp;

    string name;
    int votes;
    ifstream fin("input.txt");

    while (fin >> name >> votes)
    {
        mp[name] += votes;
    }

    for (auto& el : mp)
    {
        cout << el.first << " " << el.second << endl;
    }
}
