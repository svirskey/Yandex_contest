#include <iostream>
#include <unordered_set>
#include <set>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	unordered_set<int> uset;
	ifstream fin("input.txt");
	int tmp;
	string str;
	getline(fin, str);
	istringstream iss(str);
	
	while (iss >> tmp)
	{
		if (!uset.contains(tmp))
			uset.insert(tmp);
	}
	
	str.clear();
	getline(fin, str);
	iss.clear();
	iss.str(str);
	
	set<int> result;
	while (iss >> tmp)
	{
		if (uset.contains(tmp))
			result.insert(tmp);
	}
	for (auto&&el : result)
		cout << el << " ";
	cout << endl;
}

