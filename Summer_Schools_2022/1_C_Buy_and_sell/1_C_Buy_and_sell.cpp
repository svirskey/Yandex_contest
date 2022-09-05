#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> lst;
    int count;
    int temp;

    cin >> count;

    lst.resize(count);

    for (int i = 0; i < count; i++)
    {
        cin >> temp;
        lst[i] = temp;
    }

    int left = 0,
        right = 0;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (lst[j] - lst[i] > lst[right] - lst[left])
            {
                left = i;
                right = j;
            }
        }
    }

    if (lst[right] - lst[left] > 0)
        cout << left + 1 << " " << right + 1 << endl;
    else
        cout << 0 << " " << 0 << endl;
}
