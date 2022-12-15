#include <iostream>

using namespace std;

#define EPS 0.00001

int main()
{
	double a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	
	if (a == 0 && b == 0 && c == 0 && d == 0)
	{
		if (e == 0 && f == 0)
			cout << 5 << endl;
		else
			cout << 0 << endl;
	}
	else if ((a == 0 && b == 0 && e != 0) || (c == 0 && d == 0 && f != 0))
	{
		cout << 0 << endl;
	}
	else if (a == 0 && b == 0 && e == 0)
	{
		if (c == 0)
			cout << 4 << " " <<  f / d << endl;
		else if (d == 0)
			cout << 3 << " " << f / c << endl;
		else
			cout << 1 << " " << -c / d << " " << f / d << endl;
	}
	else if (c == 0 && d == 0 && f == 0)
	{
		if (a == 0)
			cout << 4 << " " << e / b << endl;
		else if (b == 0)
			cout << 3 << " " << e / a << endl;
		else
			cout << 1 << " " << -a / b << " " << e / b << endl;
	}
	else if (a == 0 && c == 0)
	{
		if (abs(e / b - f / d) < EPS)
			cout << 4 << " " << e / b << endl;
		else
			cout << 0 << endl;
	}
	else if (b == 0 && d == 0)
	{
		if (abs(e / a - f / c) < EPS)
			cout << 3 << " " << e / a << endl;
		else
			cout << 0 << endl;
	}
	else
	{
		double detBase = a * d - b * c;
		if (abs(detBase) < EPS)
		{
			if (abs(a * f - c * e) < EPS)
				cout << 1 << " " << -a / b << " " << e / b << endl;
			else
				cout << 0 << endl;
		}
		else
			cout << 2 << " " <<  (e * d - f * b) / detBase << " " << (a * f - c * e) / detBase << endl;
	}
}

/*
ax + by = e
cx + dy = f
*/