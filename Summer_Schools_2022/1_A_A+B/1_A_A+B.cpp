#include <iostream>

using namespace std;

int main()
{
	int count, height = 0;

	cin >> count;

	while (count >= height)
	{
		count -= height;
		height++;
	}

	cout << height - 1;
}