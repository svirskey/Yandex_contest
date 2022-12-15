#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> ann, boris, shared;
	int N, M, tmp;
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		ann.insert(tmp);
	}
	for (int i = 0; i < M; ++i)
	{
		cin >> tmp;
		if (ann.contains(tmp))
		{
			ann.erase(tmp);
			shared.insert(tmp);
		}
		else
			boris.insert(tmp);
	}
	cout << shared.size() << endl;
	for (auto& el : shared)
		cout << el << " ";
	cout << endl << ann.size() << endl;
	for (auto& el : ann)
		cout << el << " ";
	cout << endl << boris.size() << endl;
	for (auto& el : boris)
		cout << el << " ";
	cout << endl;
}

