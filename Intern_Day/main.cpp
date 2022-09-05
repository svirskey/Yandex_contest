#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    int rooms_count;
    string str;
    unordered_map<string, int> edges;
    unordered_set<string> vertices;

    cin >> rooms_count;
    for (int i = 0; i < rooms_count; i++)
    {
        cin >> str;

        for (int j = 0; j + 3 < str.length() ; j++)
        {
            string prev = str.substr(j, 3);
            string next = str.substr(j + 1, 3);
            string concated = prev + "_" + next;

            if (edges.find(concated) == edges.end())
            {
                edges.insert(make_pair(concated, 1));
                vertices.insert(prev);
                vertices.insert(next);
            }
            else
                edges[concated]++;
        }
    }
    cout << vertices.size() << endl;    
    cout << edges.size() << endl;

    for (auto &el : edges)
        cout << el.first.substr(0, 3) << " " << el.first.substr(4, 3) << " " << el.second << endl;
    
}