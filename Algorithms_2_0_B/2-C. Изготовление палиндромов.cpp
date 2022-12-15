#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int count;

    cin >> str;
    count = str.size() / 2;

    for (int i = 0; i < str.size() / 2; i++)
    {
        if (str[i] == str[str.size() - i - 1])
            count--;
    }
    cout << count << endl;
}
