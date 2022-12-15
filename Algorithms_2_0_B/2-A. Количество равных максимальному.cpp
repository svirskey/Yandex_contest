#include <iostream>

using namespace std;

int main()
{
	int max, num, count = 0;

	cin >> num;
	max = num;
	while (num != 0)
	{
		if (num > max)
		{
			max = num;
			count = 1;
		}
		else if (num == max)
			count++;
		cin >> num;
	}
	cout << count << endl;
}
