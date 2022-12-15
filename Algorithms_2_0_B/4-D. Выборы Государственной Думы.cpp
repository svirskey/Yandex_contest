#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <tuple>

using namespace std;

struct party
{
    string name;
    int votes;
    int places_count;
    double fractional;
    short order;
};

void deserialize_party(party& p, string& str)
{
    std::istringstream iss(str);
    string tmp;
    vector<string> splitted;
    while (iss >> tmp)
        splitted.push_back(tmp);

    for (int i = 0; i < splitted.size() - 1; i++)
    {
        if (p.name == "")
            p.name = splitted[i];
        else
            p.name += " " + splitted[i];
    }
    p.votes = stoi(splitted[splitted.size() - 1]);
}

int main()
{
    ifstream fin("input.txt");
    string str;
    double first_electoral = 0;
    vector<party> parties;

    int short ord = 0;
    while (getline(fin, str))
    {
        party p;
        deserialize_party(p, str);
        p.order = ord;
        parties.push_back(p);
        ord++;
    }
    for (auto& el : parties)
        first_electoral += el.votes;

    first_electoral /= 450;
    for (auto& el : parties)
    {
        el.places_count = el.votes / first_electoral;
        el.fractional = el.votes;
        el.fractional /= first_electoral;
        el.fractional -= (int)el.fractional;
    }

    sort(parties.begin(), parties.end(),
        [](party& f, party& s) {
            return std::tie(f.fractional, f.votes) > std::tie(s.fractional, s.votes); });

    int total_amount = 0;
    for (auto& el : parties)
        total_amount += el.places_count;

    for (auto& el : parties)
    {
        if (total_amount == 450)
            break;
        el.places_count++;
        total_amount++;
    }

    sort(parties.begin(), parties.end(),
        [](party& f, party& s) {
            return f.order < s.order; });

    for (auto& el : parties)
        cout << el.name << " " << el.places_count << endl;
}
