#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, K, tmp;
	cin >> N;
	vector<int> keys(N + 1);
	
	for (int i = 1; i <= N; ++i)
	{
		cin >> keys[i];
	}
	cin >> K;
	for (int i = 0; i < K; ++i)
	{
		cin >> tmp;
		keys[tmp]--;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (keys[i] < 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

