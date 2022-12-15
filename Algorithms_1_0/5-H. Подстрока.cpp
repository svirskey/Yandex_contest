#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int main()
{
	int N, K;
	string str;
	cin >> N >> K >> str;
	
	unordered_map<char, int> letters;
	
	int right = 0, 
			best_len = -1, left_ind = -1;
	
	for (int left = 0; left < N; ++left)
	{
		if (!letters.contains(str[right]))
			letters[str[right]] = 0;
		while (letters[str[right]] < K && right < N)
		{
			letters[str[right]]++;
			right++;
		}
		if (right  - left > best_len)
		{
			best_len = right - left;
			left_ind = left;
		}
		letters[str[left]]--;
	}
	cout << best_len << " " << left_ind + 1 << endl;
}