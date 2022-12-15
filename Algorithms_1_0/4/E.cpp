#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	int N;
	int weight, height;
	unordered_map<int, int> blocks;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> weight >> height;
		if (!blocks.contains(weight))
			blocks[weight] = height;
		else if (blocks[weight] < height)
			blocks[weight] = height;
	}
	long long result = 0;
	for (auto && [weight, height] : blocks)
	{
		result += height;
	}
	cout << result;
}

