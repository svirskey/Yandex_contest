#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	int N, a, b;
	unordered_set<int> uset;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> a >> b;
		if ( a >= 0 && b >= 0 && a + b == N - 1)
			uset.insert(a);
	}
	cout << uset.size() << endl;
}

