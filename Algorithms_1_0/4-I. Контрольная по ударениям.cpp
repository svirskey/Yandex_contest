#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

int upper_count(const string& str)
{
	int count = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if (isupper(str[i]))
			++count;
	}
	return count;
}

string& str_to_lower(string& str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if (isupper(str[i]))
			str[i] -= ('A' - 'a');
	}
	return str;
}

int main()
{
	ifstream fin("input.txt");
	int N, result = 0;
	string str;
	unordered_set<string> words, in_lower;
	fin >> N;
	for (int i = 0; i < N; ++i)
	{
		fin >> str;
		words.insert(str);
		in_lower.insert(str_to_lower(str));
	}
	while (fin >> str)
	{
		if ((!words.contains(str)) && 
			(upper_count(str) != 1 || in_lower.contains(str_to_lower(str))))
				++result;
	}
	cout << result << endl;
}

