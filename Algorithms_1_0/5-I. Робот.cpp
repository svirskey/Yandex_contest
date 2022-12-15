#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int K;
	string str;
	cin >> K >> str;
	
	long long prev = 0, result = 0;
	for (int i = K; i < str.length(); ++i)
	{
		if (str[i] == str[i - K])
		{
			prev++;
			result += prev;
		}
		else 
			prev = 0;
	}
	cout << result << endl;
}