#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	vector<int>::size_type n = matrix.size() - 1;
	vector<vector<int>>::size_type m = matrix[0].size();
	vector<int>::size_type i = 0;
	while (i < m)
	{
		if (matrix[n][i] > target)
		{
			if (n == 0)
				break;
			else
				n--;
		}			
		else if (matrix[n][i] < target)
			i++;
		else
			return true;		
	}
	return false;
}

//int removeDuplicates(vector<int>& nums) {
//	int length = 0;
//	map<int, int> percount;
//	vector<int>::iterator k = nums.begin();
//	while( k != nums.end())
//	{
//		if (percount.find(*k) == percount.end())
//			percount[*k] = 1;
//		else
//			percount[*k]++;
//		if (percount[*k] <= 2)
//		{
//			length++;
//			k++;
//		}
//		else
//			nums.erase(k, k);
//	}
//	return length;
//}

void print(vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
	getchar();
}
int removeDuplicates(vector<int>& nums) {
	if (nums.size() < 2)
		return nums.size();
	vector<int>::iterator i = nums.begin();
	vector<int>::iterator j = nums.begin()+1;
	int length = 0;
	while (j != nums.end())
	{
		if (*i == *j)
		{
			if (j - i <= 1)
			{
				j++;
			}				
			else
			{
				j = nums.erase(j,j+1);
			}
		}
		else{
			i = j;
			j++;
		}
	}
	return nums.size();
}
vector<int> plusOne(vector<int>& digits) {
	vector<int> result;
	if (digits.size() == 0)
		return result;
	int n = digits.size();
	digits[n - 1] += 1;
	bool ispass;
	if (digits[n - 1] == 10)
	{
		digits[n - 1] = 0;
		ispass = true;
	}
	else
	{
		ispass = false;
	}	

	for (n = n - 2; n >= 0; n--)
	{ 
		if (ispass)
		{
			if (digits[n] == 9)
				digits[n] = 0;
			else
			{
				digits[n] += 1;
				ispass = false;
			}
		}	
	}
	if (ispass)
	{
		result.push_back(1);
	}
	for (vector<int>::size_type i = 0; i < digits.size(); i++)
		result.push_back(digits[i]);
	return result;
}

int mai2n()
{
	vector<vector<int>> matrix = { {1} };
	cout << matrix.size() << " " << matrix[0].size() << endl;
	//cout << boolalpha << searchMatrix(matrix, 0) << endl;
	vector<int> nums = { 1, 1, 1, 2, 2, 2, 3 };
	cout << removeDuplicates(nums) << endl;
	getchar();
	vector<int> digits = { 9, 9, 9, 9, 9 };
	vector<int> result = plusOne(digits);
	print(result);
	return 0;
}