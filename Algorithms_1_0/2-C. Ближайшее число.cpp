#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long N, goal;
	cin >> N;
	vector<long long> arr(N);
	
	for (int i = 0 ; i < N; ++i)
		cin >> arr[i];
	
	cin >> goal;
	
	long long num = arr[0], best = abs(arr[0] - goal);
	
	for (int i = 1; i < N; ++i)
	{
		if (abs(arr[i] - goal) < best)
		{
			best = abs(arr[i] - goal);
			num = arr[i];
		}
	}
	cout << num << endl;
}