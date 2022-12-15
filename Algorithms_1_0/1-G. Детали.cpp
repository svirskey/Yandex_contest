#include <iostream>

#define EPS 0.000001

using namespace std;
int main()
{
	long long a, b, c;
	
	cin >> a >> b >> c;

	if (c < 0)
		cout << "NO SOLUTION" << endl;
	else if (a == 0)
	{
		if (c * c == b)
			cout << "MANY SOLUTIONS" << endl;
		else
			cout << "NO SOLUTION" << endl;
	}		
	else
	{
		double result = (static_cast<double>(c) * c - b) / a;
		long long result_int = (c*c - b) / a;
		if (abs(result - result_int) < EPS)
			cout << result_int << endl;
		else
			cout << "NO SOLUTION" << endl;
		
	}
}

// sqrt(ax + b) = c
// x = (c*c - b) / a