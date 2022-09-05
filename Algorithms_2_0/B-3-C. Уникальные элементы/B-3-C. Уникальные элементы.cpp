#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>


using namespace std;

void add_el(vector <pair<int, bool>>& v, int num)
{
	for (auto& el : v)
	{
		if (el.first == num)
		{
			el.second = false;
			return;
		}
	}
	v.push_back({ num, true });
}

int main()
{
	vector <pair<int, bool>> res;
	string str;

	getline(cin, str);
	istringstream ss(str);

	istream_iterator<int> begin(ss), end;
	vector<int> arr(begin, end);

	for (auto& el : arr)
		add_el(res, el);

	for (auto& elem : res)
	{
		if (elem.second)
			cout << elem.first << " ";
	}
}