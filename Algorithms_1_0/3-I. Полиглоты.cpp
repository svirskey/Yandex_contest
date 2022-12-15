#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
	int N, M;
	string tmp;
	unordered_map<string, int>at_least;
	unordered_set<string> all;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> M;
		for (int j = 0; j < M; ++j)
		{
			cin >> tmp;
			if (!at_least.contains(tmp))
				at_least[tmp] = 0;
			at_least[tmp]++;
		}
	}
	for (auto [key, value] : at_least)
	{
		if (value == N)
			all.insert(key);
	}
	cout << all.size() << endl;
	for (auto&& key : all)
		cout << key << endl;
	cout << at_least.size() << endl;
	for (auto [key, value] : at_least)
		cout << key << endl;
}

