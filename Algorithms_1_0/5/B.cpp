#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> cars(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> cars[i];
	}
	int right = 0, curr_sum = 0, result = 0;
	for (int left = 0; left < N; ++left)
	{
		while (curr_sum < K && right < N)
		{
			curr_sum += cars[right];
			++right;
		}
		if (curr_sum < K)
			break;
		if (curr_sum == K)
			++result;
		curr_sum -= cars[left];
	}
	cout << result << endl;
}