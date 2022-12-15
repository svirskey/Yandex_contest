#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	int N;
	string origin, syn;
	unordered_map<string, string> synonyms;
	
	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> origin >> syn;
		synonyms.insert({origin, syn});
		synonyms.insert({syn, origin});
	}
	cin >> origin;
	cout << synonyms[origin] << endl;
}

