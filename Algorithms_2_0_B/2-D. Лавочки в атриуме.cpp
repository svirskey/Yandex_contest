
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int len, count;
    int* arr;

    string str;
    cin >> len >> count;

    arr = new int[count];

    cin.get();
    getline(cin, str);
    istringstream ss(str);

    for (int i = 0; i < count; i++)
        ss >> arr[i];

    if (len % 2 == 1)
    {
        for (int i = 0; i < count; i++)
        {
            if (arr[i] * 2 + 1 == len)
            {
                cout << arr[i] << endl;
                break;
            }
            if (i < count - 1)
                if (arr[i] < len / 2 && arr[i + 1] > len / 2)
                {
                    cout << arr[i] << " " << arr[i + 1] << endl;
                    break;
                }
        }
    }
    else
    {
        for (int i = 0; i < count - 1; i++)
        {
            if (arr[i] < len / 2 && (arr[i + 1] >= len / 2))
            {
                cout << arr[i] << " " << arr[i + 1] << endl;
                break;
            }
        }
    }
}
