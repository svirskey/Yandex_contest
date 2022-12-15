#include <iostream>
#include <unordered_map>

using namespace std;

using dict_ = unordered_map<char,int>;

int find_eq(dict_& origin, dict_& current)
{
	int eq_count = 0;
	for (auto&& [key, value] : origin)
	{
		if (current.contains(key) && value == current[key])
			eq_count++;
	}
	return eq_count;
}

int modify_dict(dict_& origin, dict_& current, char el, int score)
{
	int result = 0;
	if (!current.contains(el))
		current[el] = 0;
	if (origin.contains(el) && origin[el] == current[el])
		result = -1;
	current[el] += score;
	if (origin[el] == current[el])
		result = 1;
	return result;
}	

int main()
{
	int g_len, S_len, result = 0;
	
	dict_ origin, current;
	string g, S;
	
	cin >> g_len >> S_len >> g >> S;
	
	for (auto&&el : g)
		origin[el]++;
	
	for (int i = 0; i < g_len; ++i)
		current[S[i]]++;
	
	int chars_eq = find_eq(origin, current);
	
	if (chars_eq == origin.size())
		++result;
	
	for (int i = g_len; i < S_len; ++i)
	{
		chars_eq += modify_dict(origin, current, S[i - g_len], -1);
		chars_eq += modify_dict(origin, current, S[i], 1);
		if (chars_eq == origin.size())
			++result;
	}
	cout << result;
}

