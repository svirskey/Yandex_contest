#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long a, b, c, count;
	cin >> a >> b >> c;
	count = a + b + c;
	
	long long left = 0, right = count, curr;
	while (left < right)
	{
		curr = (left + right) / 2;
		if (  2 * (a * 2 + b * 3 + c * 4 + curr * 5) >= 7 * (count + curr)) 
			right = curr;
		else 
			left = curr + 1;
	}
	cout << left << endl;
}