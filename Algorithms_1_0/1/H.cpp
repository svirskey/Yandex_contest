#include <iostream>

using namespace std;

int main()
{
	int a, b, n, m;
	cin >> a >> b >> n >> m;
	
	int a_min, a_max, b_min, b_max;
	
	a_min = a * (n - 1) + n;
	a_max = a * (n + 1) + n;
	b_min = b * (m - 1) + m;
	b_max = b * (m + 1) + m;
	
	if (a_min > b_max || b_min > a_max)
		cout << -1 << endl;
	else
		cout << max(a_min, b_min) << " " << min(a_max, b_max) << endl;
}