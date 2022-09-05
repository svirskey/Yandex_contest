#include <iostream>
using namespace std;

bool day_month(int day, int month, int year)
{
    if (month == 2)
    {
        if (year % 4 == 0 && day > 29)
            return false;
        else if (year % 4 != 0 && day > 28)
            return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
            return false;
    }
    return true;
}

bool isEuropian(int x, int y, int z)
{
    if (y > 12)
        return false;
    if (!day_month(x, y, z))
        return false;
    return true;
}

bool isAmerican(int x, int y, int z)
{
    if (x > 12)
        return false;
    if (!day_month(y, x, z))
        return false;
    return true;
}

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int res = 0;
    if (x == y && x < 13)
        cout << 1 << endl;
    else
    {
        res = isAmerican(x, y, z) + isEuropian(x, y, z);
        cout << 2 - res << endl;
    }
}
