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
		//str[0] = tolower(str[0]);
		//if (!isalpha(str.back()))
			//str.pop_back();
		//cout << str << endl;
		if (!uset.contains(str))
			uset.insert(str);
	}
	cout << uset.size() << endl;
}

