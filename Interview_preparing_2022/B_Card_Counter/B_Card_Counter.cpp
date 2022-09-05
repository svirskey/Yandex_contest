#include <iostream>
#include <vector>

using namespace std;


long getCardCount(int n, int k, const vector<long long>& cards)
{
    vector<long long> preffix(n), postffix(n);
    long result = 0;

    preffix[0] = cards[0];
    postffix[n - 1] = cards[n - 1];

    for (int i = 1; i < n; i++)
    {
        preffix[i] = cards[i] + preffix[i - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        postffix[i] = cards[i] + postffix[i + 1];
    }

    result = preffix[k - 1];

    for (int i = 1; i < k; i++)
    {
        if (preffix[k - i - 1] + postffix[n - i] > result)
            result = preffix[k - i - 1] + postffix[n - i];
    }

    if (postffix[n - k] > result)
        result = postffix[n - k];

    return result;
}

int readInt()
{
    int x;
    cin >> x;
    return x;
}

vector<long long> readList(int n)
{
    vector<long long> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    return res;
}

int main()
{
    int n = readInt();
    int k = readInt();
    vector<long long> cards = readList(n);
    cout << getCardCount(n, k, cards);
}