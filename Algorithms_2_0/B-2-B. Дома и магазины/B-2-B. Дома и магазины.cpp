
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#define size 10

int main()
{
    string str;
    int arr[size];
    int max, curr;
    std::getline(cin, str);

    istringstream ss(str);

    for (int i = 0; i < size; i++)
        ss >> arr[i];

    max = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 1)
        {
            curr = size;
            for (int j = 0; j < size; j++)
            {
                if (arr[j] == 2 && abs(i - j) < curr)
                {
                    curr = abs(i - j);
                }
            }
            if (i == 0)
                max = curr;
            else if (curr > max)
                max = curr;
        }
    }
    cout << max << endl;
}
