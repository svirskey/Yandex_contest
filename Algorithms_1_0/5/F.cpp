#include <iostream>

#include <vector>
#include <map>

using namespace std;
using vp = vector<pair<int64_t, int64_t>>;

int main()
{
	int64_t N, M, P, cost;
	cin >> N;
	vector<int64_t> classes(N);
	for (int i = 0; i < N; ++i)
		cin >> classes[i];
	cin >> M;
	vector<pair<int64_t, int64_t>> conds(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> P >> cost;
		conds[i] = {cost, P};
	}
	sort(conds.begin(), conds.end());
	
	int64_t result = 0;
	for (auto& room : classes)
	{
		for (auto&& [c, p] : conds)
		{
			
		}
	}
}