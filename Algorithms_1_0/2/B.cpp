#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> arr;
	int tmp;
	bool is_const = true, is_asc = true, is_wasc = true, is_desc = true, is_wdesc = true;

	cin >> tmp;
	while (tmp != -2000000000)
	{
		arr.push_back(tmp);
		cin >> tmp;
	}
	for (int i = 1; i < arr.size(); ++i)
	{
		if (arr[i - 1] == arr[i])
		{
			is_asc = is_desc = false;
		}
		else if (arr[i - 1] > arr[i])
		{
			is_const = is_asc = is_wasc = false;
		}
		else //  <
		{
			is_const = is_desc = is_wdesc = false;
		}
	}
	if (is_const)
		cout << "CONSTANT" << endl;
	else if (is_asc)
		cout << "ASCENDING " << endl;
	else if (is_wasc)
		cout << "WEAKLY ASCENDING" << endl;
	else if (is_desc)
		cout << "DESCENDING " << endl;
	else if (is_wdesc)
		cout << "WEAKLY DESCENDING" << endl;
	else 
		cout << "RANDOM" << endl;
}