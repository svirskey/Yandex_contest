#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> arr(N);
	
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	
	int best = 0, result = -1;
	
	for (int i = 0 ; i < N; ++i)
	{
		if (arr[i] > arr[best])
			best = i;
	}
	
	for (int i = 1; i < arr.size() - 1; ++i)
	{
		if (i > best && arr[i] % 10 == 5 && arr[i + 1] < arr[i])
		{
			if (result == -1 ||  arr[i] > arr[result])
				result = i;
		}
	}
	if (result == -1)
		cout << 0 << endl;
	else
	{
		int place = 1;
		for (int i = 0; i < arr.size(); ++i)
		{
			if (arr[i] > arr[result])
				place++;
		}
		cout << place << endl;
	}
	
	
}