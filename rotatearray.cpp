#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
using namespace std;

void rotate(vector<int>& nums, int k) {
	size_t size = nums.size();
	if (size < k)
		return rotate(nums, k - (int)size);
	vector<int> nums2(nums.rbegin(), nums.rbegin()+k);
	std::reverse(nums2.begin(), nums2.end());
	
	nums.insert(nums.begin(), nums2.begin(), nums2.end());
	nums.resize(size);
}

int maix1n()
{
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
	rotate(nums, 0);
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << " ";
	}
	getchar();
	return 0;
}