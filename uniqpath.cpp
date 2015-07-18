#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	if (obstacleGrid.size() == 0)
		return 0;
	vector<vector<int>>::size_type row = obstacleGrid.size(), i;
	vector<int>::size_type column = obstacleGrid[0].size(), j;
	int path[101][101];
	memset(path, 0, sizeof(path));
	if (obstacleGrid[0][0] == 1)
		return 0;
	else
		obstacleGrid[0][0] = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (obstacleGrid[i][j] == 0)
			{
				if (i == 0 && j == 0)
					path[i][j] = 1;
				else if (i == 0 && j != 0)
					path[i][j] = path[i][j - 1];
				else if (i != 0 && j == 0)
					path[i][j] = path[i - 1][j];
				else
					path[i][j] = path[i][j - 1] + path[i - 1][j];
			}
			else
				path[i][j] = 0;
			cout << i << " " << j << " " << path[i][j] << endl;
			getchar();
		}

	}
	return path[i - 1][j - 1];
}

string longestCommonPrefix(vector<string>& strs) {
	string s;
	if (strs.size() == 0)
		return s;
	if (strs.size() == 1)
		return strs[0];
	s = strs[0];
	string::size_type max = strs[0].size(), k = 0;
	for (vector<string>::size_type i = 1; i < strs.size(); i++)
	{
		for (string::size_type j = 0; j < strs[i].size(); j++)
		{
			k = 0;
			if (s[j] == strs[i][j])
				k++;
			else
				break;
		}
		max = std::min(max, k);
	}
	s.resize(max);
	return s;
}

int ma1in()
{
	vector<vector<int>> obs = {
		{0, 1}
	};
	cout << uniquePathsWithObstacles(obs) << endl;
	getchar();
	return 0;
}