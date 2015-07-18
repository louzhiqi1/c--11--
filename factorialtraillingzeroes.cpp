#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

int trailingZeroes(int n) {
	int count = 0;
	while (n)
	{
		n /= 5;
		count += n;	
	}
	return count;
}

//int titleToNumber(string s) {
//	int result = 0, count = 1;
//	if (s >= "CFDGSYY")
//		return 1000000001;
//	string::size_type length = s.size()-1;
//	for (string::size_type i = 0; i < s.size(); i++)
//		count *= 26; //hui yi chu
//	for (string::size_type i = 0; i < s.size(); i++)
//	{
//		count /= 26;
//		result += (s[i] - 'A' + 1)*count;
//	}
//	return result;
//}
//qu qiao le
int titleToNumber(string s)
{
	int result = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		result *= 26;
		result += s[i] - 'A' + 1;
	}
	return result;
}
int findPeakElement(vector<int>& nums) {
	if (nums.size() == 1)
	{
		return 0;
	}
	for (int i = 0, j = nums.size() - 1; i <= j; i++, j--)
	{
		if (nums[i] > nums[i + 1])
		{
			return i;
		}
		if (nums[j] > nums[j - 1])
		{
			return j;
		}
	}
}
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
	ListNode *cur1 = NULL, *cur2 = NULL;
	ListNode **first = &cur1, **second = &cur2;
	while (head)
	{
		if (head->val < x)
		{
			cur1 = head;
			cur1 = cur1->next;
			head = cur1;
		}
		else
		{
			cur2 = head;
			cur2 = cur2->next;
			head = cur2;
		}
	}
	if (*first)
	{
		if (*second)
		{
			cur1->next = *second;
			return *first;
		}
		else
			return *first;
	}
	else
	{
		if (*second)
			return *second;
		else
			return NULL;
	}
}
void rotate(vector<vector<int>>& matrix) {
	vector<vector<int>>::size_type n = matrix.size()-1;
	for (vector<vector<int>>::size_type i = 0; i < n-i; i++)
	{
		for (vector<vector<int>>::size_type j = i; j < n - i; j++)
		{
			vector<vector<int>>::size_type x = i, y = j, tmp;
			int prev, next = matrix[x][y];
			do
			{
				prev = next;
				tmp = x;
				x = y;
				y = n - tmp;	
				next = matrix[x][y];
				matrix[x][y] = prev;
			} while (x != i || y != j);
			matrix[i][j] = prev;
		}
	}
}

int removeElement(vector<int>& nums, int val) {
	int length = 0, i = 0, j = 0;
	while(j<nums.size())
	{
		while (j < nums.size() - 1)
		{
			if (nums[j] == val)
				j++;
			else
				break;
		}
		if (nums[j] == val)
			break;
		else
		{
			nums[i] = nums[j];
			i++;
			j++;
			length++;
		}		
	}
	nums.resize(length);
	return length;
}

int strStr(string haystack, string needle) {
	if (haystack.size() == 0 && needle.size() == 0)
	{
		return 0;
	}
	if (needle.size() > haystack.size())
	{
		return -1;
	}
	string::size_type i = 0, j = 0, count;
	while (i < haystack.size())
	{
		count = i;
		char tmp = 0;
		for (j = 0; j < needle.size(); j++)
		{
			if (haystack[i] == needle[j])
			{
				i++;
			}
			else
				break;
		}
		if (i - count == needle.size())
		{
			return count;
		}
		else if (count + j >= haystack.size())
		{
			break;
		}
		{
			i = count + 1;
		}

	}
	return -1;
}

int divide2(long long dividend, long long divisor) 
{
	//if (divisor > dividend)
	//	return 0;
	//if (divisor <= dividend && (divisor << 1 > dividend))
	//{
	//	return 1;
	//}
	//int val = 0, count = 0;
	//while (divisor << 1 <= dividend)
	//{
	//	if (val == 0)
	//		val = 2;
	//	else
	//		val = val << 1;
	//	divisor = divisor << 1;
	//	count++;
	//}
	//dividend -= divisor;
	//divisor = divisor >> count;
	//return val + divide2(dividend, divisor);
	long long temp = 0;
	int res=0;
	while (divisor <= dividend)
	{
		int cnt = 1;
		temp = divisor;

		while ((temp <<= 1) <= dividend)
		{
			cnt <<= 1;
		}
		res += cnt;
		dividend -= (temp >> 1);
	}
	return res;
}
int divide(int dividend, int divisor) {
	assert(divisor != 0);
	if (dividend == INT_MIN && divisor == -1)
		return INT_MAX;
	int res = 0;
	int flag = 1;
	long long divid = abs((long long)dividend);
	long long divi = abs((long long)divisor);
	long long temp = 0;
	if ((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
		flag = -1;
	while (divi <= divid)
	{
		int cnt = 1;
		temp = divi;

		while ((temp <<= 1) <= divid)
		{
			cnt <<= 1;
		}
		res += cnt;
		divid -= (temp >> 1);
	}
	return (int)res*flag;
}

int singleNumber(vector<int>& nums) {
	int result = nums[0];
	for (vector<int>::size_type i = 1; i < nums.size(); i++)
	{
		result = result^nums[i];
	}
	return result;
}


int m1ain()
{
	//cout << trailingZeroes(1808548329) << endl;
	//cout << titleToNumber("CFDGSXM") << endl;
	//vector<int> a = { INT_MIN };
	//cout << findPeakElement(a) << endl;
	////ListNode *a = new ListNode(1);
	////cout << partition(a, 0) << endl;
	//vector<vector<int>> matrix = {
	//	{ 1, 2, 3, 4},
	//	{ 12,13,14,5},
	//	{11,16,15,6},
	//	{10,9,8,7}
	//};
	//rotate(matrix);
	//for (int i = 0; i < 4; i++)
	//{
	//	for (int j = 0; j < 4; j++)
	//		cout << matrix[i][j] << " ";
	//	cout << endl;
	//}
	//vector<int> nums = {2, 1};
	//cout << removeElement(nums, 2) << endl;
	//cout << strStr("mississippi", "issi") << endl;
	//cout << divide(INT_MIN, 1) << endl;
	//cout << divide(0, 1) << endl;
	vector<int> nums = { 1, 2, 3, 4, 4, 2, 3 };
	cout << singleNumber(nums);
	getchar();
	return 0;
}