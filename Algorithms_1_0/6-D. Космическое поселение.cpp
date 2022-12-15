#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long n, a, b, w, h;
	cin >> n >> a >> b >> w >> h;
	
	long long left = 0, right = max(w, h), d;
	while (left < right)
	{
		d = (left + right + 1) / 2;
		if ( ( (w / (a + 2 * d)) * (h / (b + 2 * d)) >= n) || 
				((w / (b + 2 * d)) * (h / (a + 2 * d)) >= n)) 
			left = d;
		else 
			right = d - 1;
	}
	cout << left << endl;
}