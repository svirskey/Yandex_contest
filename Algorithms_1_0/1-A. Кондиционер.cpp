#include <iostream>


using namespace std;
int main()
{
	int before, after, result;
	string type;
	
	cin >> before >> after >> type;

	if (type == "freeze")
		result = min(before, after);
	else if (type == "heat")
		result = max(before, after);
	else if (type == "auto")
		result = after;
	else if (type == "fan")
		result = before;

	cout << result << endl;
}