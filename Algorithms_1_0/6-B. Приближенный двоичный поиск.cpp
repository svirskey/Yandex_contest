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
	return left;
}

int right_search(int goal, vector<int>& nums)
{
	int left = 0, right = nums.size() - 1, curr;
	while (left < right)
	{
		curr = (left + right + 1) / 2;
		if (nums[curr] <= goal)
			left = curr;
		else 
			right = curr - 1;
	}
	return left;
}

int main()
{
	int N, K, tmp;
	cin >> N >> K;
	
	vector<int> nums(N);
	for (int i = 0 ; i < N; ++i)
		cin >> nums[i];
	
	int left, right;
	for (int i = 0; i < K; ++i)
	{
		cin >> tmp;
		left = left_search(tmp, nums);
		right = right_search(tmp, nums);
		if (abs(tmp - nums[left]) < abs(tmp - nums[right]))
			cout << nums[left] << endl;
		else
			cout << nums[right] << endl;
	}
	
}