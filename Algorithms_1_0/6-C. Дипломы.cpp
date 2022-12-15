#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	long long w, h, n;
	cin >> w >> h >> n;
	
	long long left = 0, right = n * max(w,h), curr;
	while (left < right)
	{
		curr = (left + right) / 2;
		if ( (curr / w) * (curr / h) >= n)
			right = curr;
		else 
			left = curr + 1;
	}
	cout << left << endl;
}