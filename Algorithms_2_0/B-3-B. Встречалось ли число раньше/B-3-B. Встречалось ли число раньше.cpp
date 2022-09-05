#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>
#include <set>

using namespace std;

int main()
{
	set<int> v;
	string str;

	std::getline(cin, str);

	istringstream ss(str);

	std::istream_iterator<int> begin(ss), end;
	vector<int> input(begin, end);

	for (int i = 0; i < input.size(); i++)
	{
		if (v.find(input[i]) == v.end())
		{
			v.insert(input[i]);
			cout << "NO" << endl;
		}
		else
			cout << "YES" << endl;
	}
}
