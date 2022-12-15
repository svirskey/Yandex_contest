#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int add_color(unordered_map<int, int>& colors, int color)
{
	if (!colors.contains(color))
	{
		colors[color] = 0;
	}
	colors[color]++;
	if (colors[color] == 1)
		return 1;
	return 0;
}

int del_color(unordered_map<int, int>& colors, int color)
{
	colors[color]--;
	if (colors[color] == 0)
		return -1;
	return 0;
}


int main()
{
	int N,K;
	cin >> N >> K;
	vector<int> trees(N + 1);
	unordered_map<int, int> colors;
	
	for (int i = 1; i < N + 1; ++i)
	{
		cin >> trees[i];
	}
	int right = 1, 
			best_left = 1, best_right = N,
				now_colors = 0;
	
	for (int left = 1; left < N + 1; ++left)
	{
		while (now_colors < K && right < N + 1)
		{
			now_colors += add_color(colors, trees[right]);
			right++;
			//cout << now_colors << " " << left << " " << right << endl;
		}
		if (now_colors < K)
			break;
		if (right - 1 - left < best_right - best_left)
		{
			best_right = right - 1;
			best_left = left;
		}
		now_colors += del_color(colors, trees[left]);
	}
	cout << best_left << " " << best_right << endl;
}