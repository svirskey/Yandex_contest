#include <iostream>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include <sstream>

using namespace std;

string& str_to_lower(string& str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if (isupper(str[i]))
			str[i] -= ('A' - 'a');
	}
	return str;
}

void remove_forbidden(string& str)
{
	for (auto& el : str)
	{
		if (el != '_' && !isalnum(el))
			el = ' ';
	}
}
bool is_str_number(const string& str)
{
	for (auto& el : str)
	{
		if (!isdigit(el))
			return false;
	}
	return true;
}

int main()
{
	ifstream fin("input.txt");
	int N;
	string sens_status, start_status, str, word;
	
	unordered_set<string> keywords;
	unordered_map<string, pair<int,int>> ids;
	
	fin >> N >> sens_status >> start_status;
	
	bool is_sensitive = sens_status == "yes",
		 can_digit_start = start_status == "yes";
	
	for (int i = 0; i < N; ++i)
	{
		fin >> str;
		if (is_sensitive)
			keywords.insert(str);
		else
			keywords.insert(str_to_lower(str));
	}
	
	istringstream iss;
	int temp = 0;
	while (getline(fin, str))
	{
		remove_forbidden(str);
		iss.clear();
		iss.str(str);
		while (iss >> word)
		{
			if (!is_sensitive)
				str_to_lower(word);
			if ((!can_digit_start && isdigit(word[0])) || is_str_number(word) || keywords.contains(word))
				continue;
			if (!ids.contains(word))
				ids.insert({word, {0, temp++}});
			ids[word].first++;
		}
	}
	int best_count = 0;
	int best_pos = 0;
	string result;
	for (auto&& [key, pair_el] : ids)
	{
		auto&& [count, pos] = pair_el;
		//cout << key << " " << count << " " << pos << endl;
		if (count > best_count)
		{
			result = key;
			best_count = count;
			best_pos = pos;
		}
		if (best_count == count && pos < best_pos)
		{
			best_pos = pos;
			result = key;
		}
	}
	cout << result << endl;
}

