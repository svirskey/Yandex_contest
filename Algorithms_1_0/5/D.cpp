#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, R;
	cin >> N >> R;
	vector<int> places(N);
	
	for (int i = 0; i < N; ++i)
	{
		cin >> places[i];
	}
	long long result = 0, right = 0;
	
	for (int left = 0; left < N; ++left)
	{
		while (right < N && places[right] - places[left] <= R)
			++right;
		if (right == N)
			break;
		if (places[right] - places[left] > R)
			result += (N - right);
	}
	cout << result << endl;
}