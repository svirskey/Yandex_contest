
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int count, seconds = 0;
    int* arr;

    int max_el, index_max;

    string str;

    cin >> count;

    cin.get();
    std::getline(cin, str);

    istringstream ss(str);
    arr = new int[count];

    for (int i = 0; i < count; i++)
    {
        ss >> arr[i];
    }

    max_el = arr[0];
    index_max = 0;
    for (int i = 1; i < count; i++)
    {
        if (arr[i] > max_el)
        {
            max_el = arr[i];
            index_max = i;
        }
    }

    for (int i = 0; i < count; i++)
    {
        if (i != index_max)
        {
            for (int j = 0; j < arr[i]; j++)
                seconds++;
        }
    }
    cout << seconds << endl;
}
