#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
using ll = long long;
using v_p = vector<pair<int,int>>;

int main()
{
	ifstream fin("input.txt");
	v_p clothes;
	int N, color, type = 0;
	while (fin >> N)
	{
		for (int i = 0; i < N; ++i)
		{
			fin >> color;
			clothes.push_back({color, type});
		}
		++type;
	}
	sort(clothes.begin(), clothes.end());
	
	int best_div = clothes.back().first - clothes.front().first + 1;
	int curr_shirt = -1, best_shirt = -1;
	int curr_pants = -1, best_pants = -1;
	int right = 0;
	for (int left = 0; left < clothes.size(); ++left)
	{
		while ((curr_pants == -1 || curr_shirt == -1) && right < clothes.size())
		{
			auto&& [col, tp] = clothes[right];
			if (tp == 0)
				curr_shirt = col;
			else if (tp == 1)
				curr_pants = col;
			++right;
		}
		if (curr_pants == -1 || curr_shirt == -1)
			break;
		if (abs(curr_pants - curr_shirt) < best_div)
		{
			best_shirt = curr_shirt;
			best_pants = curr_pants;
			best_div = abs(curr_pants - curr_shirt);
		}
		if (clothes[left].second == 0 && curr_shirt == clothes[left].first)
			curr_shirt = -1;
		else if (clothes[left].second == 1 && curr_pants == clothes[left].first)
			curr_pants = -1;
	}
	cout << best_shirt << " " << best_pants << endl;
}

