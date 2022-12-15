#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	int N, M, x_p, y_p;
	ifstream fin("input.txt");
	fin >> N;
	
	vector<int> points(N), increase(N  + 1, 0), descrease(N  + 1, 0);
	
	for (int i = 0; i < N; ++i)
	{
		fin >> x_p >> points[i];
	}

	for (int i = 2; i < N + 1; ++i)
	{
		increase[i] = increase[i - 1];
		descrease[i] = descrease[i - 1];
		if (points[i - 1] > points[i - 2])
			increase[i] += (points[i - 1] - points[i - 2]);
		if (points[i - 1] < points[i - 2])
			descrease[i] += (points[i - 2] - points[i - 1]);
	}
	// for (auto&el : increase)
		// cout << el << " ";
	// cout << endl;
	// for (auto&el : descrease)
		// cout << el << " ";
	// cout << endl;
	fin >> M;
	for (int i = 0; i < M; ++i)
	{
		fin >> x_p >> y_p;
		if (x_p < y_p)
		{
			cout << increase[y_p] - increase[x_p] << endl;
		}
		else if (x_p > y_p)
		{
			cout << descrease[x_p] - descrease[y_p] << endl;
		}
		else
			cout << 0 << endl;
	}
	
}