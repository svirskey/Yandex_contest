#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	int result = 0, num;
	vector<int> arr;
	ifstream fin("input.txt");
	
	while (fin >> num)
	{
		arr.push_back(num);
	}
	
	for (int i = 1; i < arr.size() - 1; ++i)
	{
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
			result++;
	}
	cout << result << endl;
	
	return 0;
}