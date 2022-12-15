#include <iostream>
#include <vector>

using namespace std;

void fill_neighbours(int row, int col, vector<vector<char>>&field)
{
	static int arr_row[] {1,  1, 1,  0, 0, -1, -1, -1};
	static int arr_col[] {-1, 0, 1, -1, 1, -1, 0,  1};
	
	for (int i = 0 ; i < 8; ++i)
	{
		if (field[row + arr_row[i]][col + arr_col[i]] != '*')
			field[row + arr_row[i]][col + arr_col[i]]++;
	}
}

int main()
{
	int rows, cols, mines;
	
	cin >> rows >> cols >> mines;
	vector<vector<char>> field(rows + 2);
	for (int i = 0; i < rows + 2; ++i)
		field[i] = vector<char>(cols + 2, '0');
	
	int row, col;
	for (int i = 0; i < mines; ++i)
	{
		cin >> row >> col;
		field[row][col] = '*';
	}
	for (int i = 1; i <= rows; ++i)
	{
		for (int j = 1; j <= cols; ++j)
		{
			if (field[i][j] == '*')
				fill_neighbours(i, j, field);
		}
	}
	for (int i = 1; i <= rows; ++i)
	{
		for (int j = 1; j <= cols; ++j)
			cout << field[i][j] << " ";
		cout << endl;
	}
}