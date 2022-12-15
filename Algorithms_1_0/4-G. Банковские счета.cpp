#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	string type, from, to;
	int how;
	unordered_map<string, int> accounts;
	
	while (fin >> type)
	{
		if (type == "DEPOSIT")
		{
			fin >> to >> how;
			accounts[to] += how;
		}
		else if (type == "WITHDRAW")
		{
			fin >> from >> how;
			accounts[from] -= how;
		}
		else if (type == "BALANCE")
		{
			fin >> from;
			if (accounts.contains(from))
				cout << accounts[from] << endl;
			else
				cout << "ERROR" << endl;
		}
		else if (type == "TRANSFER")
		{
			fin >> from >> to >> how;
			accounts[from] -= how;
			accounts[to] += how;
		}
		else if (type == "INCOME")
		{
			fin >> how;
			for (auto&& [key, value] : accounts)
			{
				if (value > 0)
					value += (value * how) / 100;
			}
		}
	}
}

