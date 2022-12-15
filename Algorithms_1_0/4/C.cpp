#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("input.txt");
	string str;
	map<string, int> words;
	
	while (fin >> str)
	{
		if (!words.contains(str))
			words[str] = 0;
		words[str]++;
	}
	int max_el = 0;
	string result;
	for (auto && [key, value] : words)
	{
		if (value > max_el)
		{
			max_el = value;
			result = key;
		}
	}
	cout << result << endl;
}

