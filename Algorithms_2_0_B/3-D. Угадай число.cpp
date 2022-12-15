#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void fill_v(vector<int>& v, istringstream& ss, bool what)
{
	int tmp;

	if (what)
	{
		while (ss >> tmp)
			v.push_back(tmp);
	}
	else
	{
		while (ss >> tmp)
			v.push_back(tmp);
	}
}

int main()
{
	int  max_el;

	string str;
	getline(cin, str);

	istringstream ss;
	ss.str(str);
	ss >> max_el;

	vector<bool> v;
	vector<int> temp;

	v.resize(max_el + 1);

	for (auto el : v)
		el = true;

	while (str != "HELP")
	{
		temp.clear();

		getline(cin, str);

		ss.clear();
		ss.str(str);

		if (str == "HELP")
			break;

		str.clear();
		getline(cin, str);

		if (str == "YES")
		{
			fill_v(temp, ss, true);

			vector<int> res;

			for (auto& el : temp)
			{
				if (v[el])
					res.push_back(el);
			}
			for (auto el : v)
				el = false;
			for (auto& el : res)
				v[el] = true;

		}
		else // no
		{
			fill_v(temp, ss, false);

			for (auto& el : temp)
				v[el] = false;
		}
	}

	for (int i = 1; i < v.size(); i++)
	{
		if (v[i])
			cout << i << " ";
	}
}
