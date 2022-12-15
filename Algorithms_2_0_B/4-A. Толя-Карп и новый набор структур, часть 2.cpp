#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<long long, long long> mp;
    int n;

    cin >> n;

    long long d, a;
    for (int i = 0; i < n; i++)
    {
        cin >> d >> a;
        mp[d] += a;
    }
    for (auto& el : mp)
    {
        cout << el.first << " " << el.second << endl;
    }
}
