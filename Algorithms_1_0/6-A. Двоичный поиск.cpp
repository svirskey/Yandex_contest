#include <iostream>
#include <vector>


using namespace std;

int left_search(int goal, vector<int>& nums)
{
	int left = 0, right = nums.size() - 1, curr;
	while (left < right)
	{
		curr = (left + right) / 2;
		if (nums[curr] >= goal)
			right = curr;
		else 
			left = curr + 1;
	}
	return nums[left];
}

int main()
{
	int N, K, tmp;
	cin >> N >> K;
	
	vector<int> nums(N);
	for (int i = 0 ; i < N; ++i)
		cin >> nums[i];

	for (int i = 0; i < K; ++i)
	{
		cin >> tmp;
		if (left_search(tmp, nums) == tmp)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
}