#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;

	if (a == 0 && b == 0 && (c != 0 || d != 0))
		cout << "INF" << endl;
	else if (b * c == a * d)
		cout << "NO" << endl;
	else if ((static_cast<double>(b) / a) - b / a == 0)
		cout << -b / a << endl;
	else
		cout << "NO" << endl;
}
