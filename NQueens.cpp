#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

void print(vector<vector<string>> r)
{
	for (int i = 0; i < r.size(); i++)
	{
		for (int j = 0; j < r[i].size(); j++)
		{
			cout << r[i][j] << endl;
		}
		cout << endl;
	}
}
bool check(const vector<string> &lines, int i, int j, int n)
{
	// 只用找行
	for (int m = 0; m < i; m++)
		if (lines[m][j] == 'Q')
			return false;
	// 左上斜线
	for (int x = i - 1, y = j - 1; x >= 0 && y >= 0; x--, y--)
		if (lines[x][y] == 'Q')
			return false;
	// 右下斜线
	for (int x = i - 1, y = j+1; x >= 0 && y < n; x--, y++)
		if (lines[x][y] == 'Q')
			return false;
	return true;
}

void solveNQueens(int &count, vector<string> lines, int row, int N)
{
	if (row == N)
	{
		count++;
		return;
	}
	for (int j = 0; j < N; j++)
	{
		if (check(lines, row, j, N))
		{
			lines[row][j] = 'Q';
			solveNQueens(count, lines, row + 1, N);
			lines[row][j] = '.';
		}
	}
}
int solveNQueens(int n) {
	int count = 0;
	vector<string> lines;
	for (int i = 0; i < n; i++)
	{
		string line(n, '.');
		lines.push_back(line);
	}
	solveNQueens(count, lines, 0, n);
	return count;
}



int mai1n()
{
	cout << solveNQueens(4);
	getchar();
	return 0;
}

