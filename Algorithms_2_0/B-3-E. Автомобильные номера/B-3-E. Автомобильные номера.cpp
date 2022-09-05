#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int count_people,
        count_numbers;

    vector<string> people;
    vector< pair <string, int> > numbers;

    cin >> count_people;
    people.resize(count_people);

    for (int i = 0; i < count_people; i++)
    {
        cin >> people[i];
    }

    cin >> count_numbers;
    numbers.resize(count_numbers);

    for (int i = 0; i < count_numbers; i++)
    {
        cin >> numbers[i].first;
        numbers[i].second = 0;
    }

    for (int i = 0; i < count_numbers; i++)
    {
        for (int j = 0; j < count_people; j++)
        {
            int count_good = 0;
            for (int k = 0; k < people[j].size(); k++)
            {

                for (int l = 0; l < numbers[i].first.size(); l++)
                {
                    if (people[j][k] == numbers[i].first[l])
                    {
                        count_good++;
                        break;
                    }
                }
            }
            if (count_good == people[j].size())
                numbers[i].second++;
        }
    }

    int max = numbers[0].second;
    for (int i = 1; i < count_numbers; i++)
    {
        if (max < numbers[i].second)
            max = numbers[i].second;
    }

    for (int i = 0; i < count_numbers; i++)
    {
        if (numbers[i].second == max)
            cout << numbers[i].first << endl;
    }
}
