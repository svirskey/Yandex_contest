#include <iostream>
#include <unordered_set>
#include <fstream>

using namespace std;

int main()
{
	unordered_set<int> set;
	ifstream fin("input.txt");
	int tmp;
	while (fin >> tmp)
	{
		if (!set.contains(tmp))
			set.insert(tmp);
	}
	cout << set.size() << endl;
}

