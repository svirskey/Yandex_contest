
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	string str;


	int placeToBuild;
	int count;
	int* arr;

	cin >> count;
	arr = new int[count];

	cin.get();
	std::getline(cin, str);

	istringstream ss(str);

	for (int i = 0; i < count; i++)
		ss >> arr[i];

	cout << arr[count / 2] << endl;
}