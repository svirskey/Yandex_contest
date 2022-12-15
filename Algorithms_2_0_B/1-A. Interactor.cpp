#include <iostream>

using namespace std;

int main()
{
    short   endedTask,
        interactor,
        checker;

    cin >> endedTask;
    cin >> interactor;
    cin >> checker;
    switch (interactor)
    {
    case 0:
    {
        if (endedTask == 0)
            cout << checker << endl;
        else
            cout << 3 << endl;
        break;
    }
    case 1:
    {
        cout << checker << endl;
        break;
    }
    case 4:
    {
        if (endedTask == 0)
            cout << 4 << endl;
        else
            cout << 3 << endl;
        break;
    }
    case 6:
    {
        cout << 0 << endl;
        break;
    }
    case 7:
    {
        cout << 1 << endl;
        break;
    }
    default:
        cout << interactor << endl;
    }
}
