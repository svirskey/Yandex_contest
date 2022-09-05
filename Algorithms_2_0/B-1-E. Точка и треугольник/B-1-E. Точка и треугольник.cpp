#include <iostream>
using namespace std;

int main()
{
	short d, x, y;
	cin >> d;
	cin >> x >> y;

	if (x >= 0 && y >= 0 && x + y <= d)
		cout << 0 << endl;
	else if (x <= d / 2 && y <= d / 2)
		cout << 1 << endl;
	else if (y <= x)
		cout << 2 << endl;
	else
		cout << 3 << endl;
}
