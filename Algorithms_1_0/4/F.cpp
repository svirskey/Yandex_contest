#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	string name, type;
	long long count;
	map<string, map<string, long long>> clients;
	
	while (fin >> name >> type >> count)
	{
		clients[name][type] += count;
	}
	for (auto && [name, list] : clients)
	{
		cout << name << ":" << endl;
		for (auto && [type, count] : list)
		{
			cout << type << " " << count << endl;
		}
	}
	
}

