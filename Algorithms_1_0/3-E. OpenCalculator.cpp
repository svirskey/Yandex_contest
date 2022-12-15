#include <iostream>

using namespace std;

int main()
{
	unordered_set<string> uset;
	int x,y,z;
	string number;
	bool nums[10] {false};
	cin >> x >> y >> z >> number;
	
	for (auto &&el : number)
		nums[el - '0'] = true;
	nums[x] = nums[y] = nums[z] = false;
	int result = 0;
	for (int i = 0; i < 10; ++i)
	{
		if (nums[i])
			result++;
	}
	cout << result << endl;
}

