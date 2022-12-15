#include <iostream>
using namespace std;

int main()
{
    short count, from, to;
    short tmp;
    cin >> count >> from >> to;
    if (to < from)
    {
        tmp = to;
        to = from;
        from = tmp;
    }
    if (to - from > count / 2)
        cout << count - to + from - 1 << endl;
    else
        cout << to - from - 1 << endl;
}