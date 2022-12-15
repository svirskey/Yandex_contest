#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int N;
	double left = 30., right = 4000.;
	ifstream fin("input.txt");
	double prev, curr, step;
	string type;
	fin >> N;
	fin >> prev;
	for (int i = 1; i < N; ++i)
	{
		fin >> curr >> type;
		step = abs(curr - prev) / 2;
		if (type == "closer")
		{
			if (curr > prev && curr - step > left)
				left = curr - step;
			else if (curr < prev && curr + step < right)
				right = curr + step;
		}
		else if (type == "further")
		{
			if (curr > prev && prev + step < right)
				right = prev + step;
			else if (curr < prev && prev - step > left)
				left = prev - step;
		}
		prev = curr;
	}
	cout << fixed << left << " " << right << endl;
}