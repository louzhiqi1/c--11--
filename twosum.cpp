#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> twosum(vector<int> &nums, int target)
{
	vector<int> result;
	multimap<int, int> keymap;
	for (size_t i = 0; i < nums.size(); i++)
	{
		keymap.insert(pair<int, int>(nums[i], i + 1));
	}
	
	sort(nums.begin(), nums.end());
	for (size_t i = 0, j = nums.size() - 1; i < nums.size();)
	{
		if (nums[i] + nums[j] == target)
		{
			multimap<int, int>::iterator itr, jtr;
			if (nums[i] == nums[j])
			{
				itr = keymap.find(nums[i]);
				jtr = itr++;
			}
			else
			{
				itr = keymap.find(nums[i]),
				jtr = keymap.find(nums[j]);
			}
			if ((*jtr).second < (*itr).second)
			{
				result.push_back((*jtr).second);
				result.push_back((*itr).second);		
			}
			else
			{
				result.push_back((*itr).second);
				result.push_back((*jtr).second);
			}
				
			break;			
		}
		else if (nums[i] + nums[j] > target)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	return result;
}

int test()
{
	vector<int> num = { -1, -2, -3, -4, -5 };
	int target = -8;
	vector<int> result = twosum(num, target);
	if (result.empty())
		cout << "null" << endl;
	else
	{
		for (vector<int>::iterator itr = result.begin(); itr != result.end(); itr++)
			cout << *itr << " ";
		cout << endl;
	}
	getchar();
	return 0;
}