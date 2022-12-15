#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<string> pairs;
	string first, second;
	cin >> first >> second;
	for (auto it = second.begin(); it + 1 != second.end(); ++it)
	{
		pairs.insert({it, it + 2});
	}
	string tmp;
	int result = 0;
	for (auto it = first.begin(); it + 1 != first.end(); ++it)
	{
		if (pairs.contains({it, it + 2}))
			result++;
	}
	cout << result << endl;
}

