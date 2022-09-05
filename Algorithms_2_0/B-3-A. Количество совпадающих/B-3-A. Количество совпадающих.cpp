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
	std::istream_iterator<int> begin1(ss), end1;
	set<int> input1(begin1, end1);

	ss.clear();
	std::getline(cin, str);
	ss.str(str);

	std::istream_iterator<int> begin2(ss), end2;
	set<int> input2(begin2, end2);


	auto i = input1.begin();
	auto j = input2.begin();
	int res = 0;


	while (i != input1.end() && j != input2.end())
	{
		if (*i < *j)
			i++;
		else if (*i > *j)
			j++;
		else
		{
			res++;
			i++;
			j++;
		}
	}
	cout << res << endl;

}
