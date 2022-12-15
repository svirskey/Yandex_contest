#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	int tmp;
	vector<long long> arr;
	
	while (fin >> tmp)
		arr.push_back(tmp);
	
	int min1 = 0, min2 = -1, max1 = -1, max2 = 0; // -10 -5 1 5

	for (int i = 1; i < arr.size(); ++i)
	{
		if (arr[i] > arr[max2])
			max2 = i;
		if (arr[i] < arr[min1])
			min1 = i;
	}
	for (int i = 0; i < arr.size(); ++i)
	{
		if (min2 == -1 && i != min1)
			min2 = i;
		if (max1 == -1 && i != max2)
			max1 = i;
		if (arr[i] > arr[max1] && i != max2)
			max1 = i;
		if (arr[i] < arr[min2] &&  i != min1)
			min2 = i;
	}
	
	if (arr[min1] * arr[min2] > arr[max1] * arr[max2])
		cout << arr[min1] << " " << arr[min2] << endl;
	else
		cout << arr[max1] << " " << arr[max2] << endl;
}