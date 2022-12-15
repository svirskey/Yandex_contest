#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <fstream>

using namespace std;
using vp = vector<pair<int64_t, int64_t>>;

int main()
{
	ifstream fin("input.txt");
	int64_t N, x, y;
	fin >> N;
	vp points(N);
	for (int i = 0; i < N; ++i)
	{
		fin >> x >> y;
		points[i] = {x, y};
	}
	
	int64_t result = 0;
	for (int i = 0; i < N; ++i)
	{
		auto &&[x1,y1] = points[i];

		vector<int64_t> sides;
		set<pair<int64_t,int64_t>> used_points; 
		for (int j = 0; j < N; ++j)
		{
			auto &&[x2,y2] = points[j];
			int64_t lenn = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
			sides.push_back(lenn);
			if (used_points.contains({x1 - x2, y1 - y2}))
				--result;
			used_points.insert({x2 - x1,y2 - y1});
		}
		sort(sides.begin(), sides.end());
		int right = 0;
		for (int left = 0; left < sides.size(); ++left) 
		{
			while (right < sides.size() && sides[left] == sides[right])
				++right;
			result += right - left - 1;
		}
	}
	cout << result << endl;
}