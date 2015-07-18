#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
#include <Windows.h>
#include <winbase.h>
#include <unordered_set>
using namespace std;

//bool valid(vector<vector<char>> board, int row, int col)
//{
//	// 行
//	for (int j = 0; j < 9; j++)
//	{
//		if (j == col)
//			continue;
//		if ( board[row][j] == board[row][col])
//			return false;
//	}
//	// 列
//	for (int j = 0; j < 9; j++)
//	{
//		if (j == row)
//			continue;
//		if (board[j][col] == board[row][col])
//			return false;
//	}
//	// 小三角
//	for (int i = row / 3 * 3; i < row/3*3+3; i++)
//	{
//		for (int j = col / 3 * 3; j < col/3*3+3; j++)
//		{
//			if ((i == row && j == col))
//				continue;
//			if (board[i][j] == board[row][col])
//				return false;
//		}
//	}
//	return true;
//
//}
//bool solveSudoku(vector<vector<char>> &board, int row, int col)
//{
//	if (row == 9 && col == 0)
//		return true;
//	if (board[row][col] == 0)
//	{
//		char k;
//		for (k = 1; k < 10; k++)
//		{
//			board[row][col] = k;
//			if (valid(board, row, col))
//			{
//				if (col == 8)
//				{
//					if (!solveSudoku(board, row + 1, 0))
//						continue;
//					else
//					{
//						break;
//					}
//				}
//				else
//				{
//					if (!solveSudoku(board, row, col + 1))
//						continue;
//					else
//						break;
//				}
//			}
//		}
//		if (k == 10)
//		{
//			board[row][col] = 0;
//			return false;
//		}
//	}
//	if (col == 8)
//	{
//		solveSudoku(board, row + 1, 0);
//	}
//	else
//	{
//		solveSudoku(board, row, col + 1);
//	}
//}
//
//void solveSudoku(vector<vector<char>>& board) {
//	solveSudoku(board, 0, 0);
//}

class Solution {
public:
	bool dfs(vector<vector<char>>& board, int i, int j)
	{
		while (i <= 8 && j <= 8 && board[i][j] != 0)//find next empty cell
		{
			if (j == 8)                //find empty cell in next row
			{
				j = 0;
				++i;
			}
			else if (j<8)            // find empty cell in next col
				++j;
		}

		if (i == 9)                // i==9 means all the cells are filled 
			return true;
		char n;
		int x = i / 3;
		int y = j / 3;
		for (int k = 1; k <= 9; ++k)
		{
			n = k ;          // enumerate all possible digit
			if (row[i].find(n) == row[i].end() && col[j].find(n) == col[j].end() && cell[x][y].find(n) == cell[x][y].end())
			{
				row[i].insert(n);
				col[j].insert(n);
				cell[x][y].insert(n);
				board[i][j] = n;
				if (dfs(board, i, j))
					return true;
				else
				{
					row[i].erase(n);
					col[j].erase(n);
					cell[x][y].erase(n);
					board[i][j] = 0;
				}
			}
		}
		return false;
	}
	void solveSudoku(vector<vector<char>>& board) {
		for (int i = 0; i<9; ++i)
			for (int j = 0; j<9; ++j)
			{
				if (board[i][j] != 0)
				{
					int x = i / 3;
					int y = j / 3;
					row[i].insert(board[i][j]);
					col[j].insert(board[i][j]);
					cell[x][y].insert(board[i][j]);
				}
			}
		dfs(board, 0, 0);
		return;
	}
private:
	unordered_set<char> row[9];
	unordered_set<char> col[9];
	unordered_set<char> cell[3][3];
};

void print2(vector<vector<char>> r)
{
	for (int i = 0; i < r.size(); i++)
	{
		for (int j = 0; j < r[i].size(); j++)
		{
			cout << r[i][j]+0 << " ";
		}
		cout << endl;
	}
}
//*Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) 
{
	ListNode* cur = head;
	while (cur)
	{
		ListNode* cur2 = cur;
		int i;
		for (i = 0; i < k; i++)
		{
			if (cur2)
				cur2 = cur2->next;
			else
				break;
		}
		if (i == k)
		{
			ListNode* tmp = cur2->next;
			while (--i)
			{
				cur2->next = cur->next;
				cur = cur2;
			}
		}
		else
		{
			break;
		}
	}
	return head;
}

int maximumGap(vector<int>& nums) {
	if (nums.size() < 2)
		return 0;
	vector<int> result;
	int max = 0, min = nums[0];
	for (int i = 0; i < nums.size();i++)
	{
		if (nums[i] > max)
			max = nums[i];
	}
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] < min)
			min = nums[i];
	}
	int gap = ceil((double)(max - min) / nums.size());
	vector<vector<int> > buckets;
	for (int i = 0; i <= nums.size(); i++)
	{
		vector<int> bucket;
		buckets.push_back(bucket);
	}
	for (int i = 0; i < nums.size(); i++)
	{
		int bucketIndex = (nums[i] - min) / gap;
		buckets[bucketIndex].push_back(nums[i]);
	}
	int maxgap = 0;
	int prev = min;
	for (int i = 0; i < buckets.size(); i++)
	{
		if (buckets[i].empty())
			continue;
		int bucketMin = buckets[i][0];
		for (int j = 0; j < buckets[i].size(); j++)
			if (bucketMin>buckets[i][j])
			{
				bucketMin = buckets[i][j];
			}
		int bucketMax = 0;
		for (int j = 0; j < buckets[i].size(); j++)
			if (bucketMax<buckets[i][j])
			{
				bucketMax = buckets[i][j];
			}
		int cur = (bucketMax - bucketMin) >(bucketMin - prev) ? (bucketMax - bucketMin) : (bucketMin - prev);
		maxgap = maxgap > cur ? maxgap : cur;
		prev = bucketMax > prev ? bucketMax : prev;
	}
	return maxgap;
}

int main()
{
	//vector<vector<char>> board = {
	//	{ 0, 0, 9, 7, 4, 8, 0, 0, 0},
	//	{ 7, 0, 0, 0, 0, 0, 0, 0, 0 },
	//	{ 0, 2, 0, 1, 0, 9, 0, 0, 0 },
	//	{ 0, 0, 7, 0, 0, 0, 2, 4, 0 },
	//	{ 0, 6, 4, 0, 1, 0, 5, 9, 0 },
	//	{ 0, 9, 8, 0, 0, 0, 3, 0, 0 },
	//	{ 0, 0, 0, 8, 0, 3, 0, 2, 0 },
	//	{ 0, 0, 0, 0, 0, 0, 0, 0, 6 },
	//	{ 0, 0, 0, 2, 7, 5, 9, 0, 0 }
	//};
	//print2(board);
	//DWORD dwStart = ::GetTickCount();
	//Solution s;
	//s.solveSudoku(board);
	//DWORD dwEnd = GetTickCount();
	//cout << dwEnd - dwStart << endl;
	//print2(board);
	vector<int> nums = { 15252, 16764, 27963, 7817, 26155, 20757, 3478, 22602, 20404, 6739, 16790, 10588, 16521, 6644, 20880, 15632, 27078, 25463, 20124, 15728, 30042, 16604, 17223, 4388, 23646, 32683, 23688, 12439, 30630, 3895, 7926, 22101, 32406, 21540, 31799, 3768, 26679, 21799, 23740 };
	cout << maximumGap(nums);
	getchar();
	return 0;
}