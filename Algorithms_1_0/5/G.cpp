#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	int64_t N, K, tmp;
	map<int64_t, int64_t> dict;
	fin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		fin >> tmp;
		if (!dict.contains(tmp))
			dict.insert({tmp, 0});
		dict[tmp]++;
	}
	auto right = dict.begin();
	int64_t repeats = 0, result = 0;
	auto dict_end = dict.end();
	auto left = dict.begin();
	int64_t len = 0;
	for (; left != dict_end; ++left)
	{
		while (right != dict_end && (left->first) * K >= right->first)
		{
			if (right->second > 1)
				++repeats;
			++len;
			++right;
		}
		result += (len - 1) * (len - 2) * 3;
		if (left->second > 1)
			result += (len - 1) * 3;
		if (left->second > 2)
			result++;
		if (left->second > 1)
			repeats--;
		result += repeats * 3;
		--len;
	}
	cout << result << endl;
}