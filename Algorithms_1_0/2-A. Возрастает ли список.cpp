#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int num, prev;
	bool was_prev = false;
	ifstream fin("input.txt");
	
	while (fin >> num)
	{
		if (was_prev && num <= prev)
		{
			cout << "NO" << endl;
			return 0;
		}
		prev = num;
		was_prev = true;
	}
	cout << "YES" << endl;
	return 0;
}