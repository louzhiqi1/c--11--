#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
#include <unordered_map>
#include <list>
using namespace std;

int rob(vector<int>& nums)
{
	int total = 0;
	vector<int> result(nums.size(),0);
	result[0] = nums[0];
	result[1] = nums[1];
	for (int i = 2; i < nums.size(); i++)
	{
		result[i] = result[i - 2] + nums[i];
		total = max(total, result[i]);
	}
	return total;
}

int m3ain()
{
	vector<int> nums{ 1, 2, 3, 4, 5, 6, 8, 1 };
	cout << rob(nums) << endl;
	getchar();
	return 0;
}
