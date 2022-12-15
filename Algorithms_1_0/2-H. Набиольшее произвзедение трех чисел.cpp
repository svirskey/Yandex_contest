#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

using ll = long long;

int main()
{
	ifstream fin("input.txt");
	int tmp;
	vector<ll> arr;
	
	while (fin >> tmp)
		arr.push_back(tmp);
	
	int min1 = -1, min2 = -1, max1 = -1, max2 = -1, max_el = 0; // -10 -5 1 5

	for (int i = 1; i < arr.size(); ++i)
	{
		if (arr[i] > arr[max_el])
			max_el = i;
	}
	
	for (int i = 0; i < arr.size(); ++i)
	{
		if (i != max_el)
		{
			if (max2 == -1)
				max2 = i;
			if (arr[i] > arr[max2])
				max2 = i;
			
			if (min1 == -1)
				min1 = i;
			if (arr[i] < arr[min1])
				min1 = i;
		}
	}
	
	for (int i = 0; i < arr.size(); ++i)
	{
		if (i != max_el)
		{
			if (i != max2)
			{
				if (max1 == -1)
					max1 = i;
				if (arr[i] > arr[max1])
					max1 = i;
			}
			if (i != min1)
			{		
				if (min2 == -1)
					min2 = i;
				if (arr[i] < arr[min2])
					min2 = i;
			}
		}
	}
	cout << arr[max_el] << " ";
	if (arr[max_el] > 0)
	{
		if (arr[min1] * arr[min2] > arr[max1] * arr[max2])
			cout << arr[min1] << " " << arr[min2] << endl;
		else
			cout << arr[max1] << " " << arr[max2] << endl;
	}
	else
	{
		if (arr[min1] * arr[min2] > arr[max1] * arr[max2])
			cout << arr[max1] << " " << arr[max2] << endl;
		else
			cout << arr[min1] << " " << arr[min2] << endl;
	}
	
}