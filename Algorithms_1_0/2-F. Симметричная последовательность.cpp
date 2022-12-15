#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	std::cin >> N;
	vector<int> arr(N);
	vector<int> result;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	
	for (int i = 0; i < N; ++i)
	{
		int left = i, right = N - 1;
		while (left <= right && left < N && right >= 0 && arr[left] == arr[right])
		{
			++left;
			--right;
		}
		if (left > right)
		{
			for (int j = i - 1; j >= 0; --j)
				result.push_back(arr[j]);
			break;
		}	
	}
	cout << result.size() << endl;
	for (auto&el : result)
		cout << el << " ";
}

