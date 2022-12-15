#include <iostream>
#include <unordered_set>
#include <fstream>

using namespace std;

int main()
{
	unordered_set<string> uset;
	ifstream fin("input.txt");
	string str;
	
	while (fin >> str)
	{
		if (!uset.contains(str))
			uset.insert(str);
	}
	cout << uset.size() << endl;
}

