#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	int N, x, y, result = 0;
	unordered_set<int> uset;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		if (!uset.contains(x))
		{
			uset.insert(x);
			result++;
		}
	}
	cout << result << endl;
}

