#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long getNumberOfGoodPairs(int n, const vector<int>& a)
{
    int pairCount = 0;

    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (abs(a[j] - a[i]) % 200 == 0)
                pairCount++;
        }
    }*/

    // TODO = MAP

    return pairCount;
}

int readInt()
{
    int x;
    cin >> x;
    return x;
}

vector<int> readList(int n)
{
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        cin >> res[i];
    }
    return res;
}

int main() {
    int n = readInt();
    vector<int> numbers = readList(n);
    cout << getNumberOfGoodPairs(n, numbers);
}