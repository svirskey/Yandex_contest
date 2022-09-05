#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    map<string, int> mp;

    string name;
    ifstream fin("input.txt");

    while (fin >> name)
    {
        mp[name]++;
    }
    map<pair<int, string>, bool> result;

    int max_count = 0;
    for (auto& el : mp)
    {
        if (el.second > max_count)
            max_count = el.second;
    }

    for (auto& el : mp)
    {
        el.second = max_count - el.second;
    }

    for (auto& el : mp)
    {
        result[{el.second, el.first}] = true;
    }

    for (auto& el : result)
    {
        cout << el.first.second << endl;
    }
}
