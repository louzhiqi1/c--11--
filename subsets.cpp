#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums, vector<vector<int>>& result);
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int> > result;
	if (nums.size() == 0)
	{
		return result;
	}
	return subsets(nums, result);
}
vector<vector<int>> subsets(vector<int>& nums, vector<vector<int>>& result)
{
	if (nums.empty())
	{
		vector<int> sub4;
		result.push_back(sub4);
		for (int i = 0; i < result.size(); i++)
		{
			for (int j = 0; j < result[i].size(); j++)
			{
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
		getchar();
		return result;
	}
	else
	{
		int num = nums[nums.size()-1];
		nums.pop_back();
		int len = result.size();
		for (int i = 0; i < len; i++)
		{	
			vector<int> sub(result[i].begin(), result[i].end());
			sub.push_back(num);
			result.push_back(sub);
		}
		vector<int> sub1 = { num };
		result.push_back(sub1);
		subsets(nums, result);
	}
}

int mai22n()
{
	vector<int> nums = { 1, 2, 3 };
	vector<vector<int>> result = subsets(nums);
	cout << "hhh" << endl;
	getchar();
	for (int i = 0; i < result.size(); i++)
	{
		for (int j = 0; j < result[i].size(); j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	getchar();
	return 0;
}

