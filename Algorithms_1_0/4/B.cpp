#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	string str;
	unordered_map<string, int> words;
	
	while (fin >> str)
	{
		if (!words.contains(str))
			words[str] = 0;
		cout << words[str] << " ";
		words[str]++;
	}
	cout << endl;
}

