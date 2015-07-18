#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
#include <list>
using namespace std;

int findMin(vector<int>& nums) {
	vector<int>::size_type size = nums.size(), i = 0, j = size - 1;
	if (size == 0)
		return 0;
	while (j - i > 1)
	{
		if (nums[(j-i)/2+i] > nums[j])
		{
			i = (j - i) / 2 + i;
		}
		else
		{
			j = (j - i) / 2 + i;
		}
	}
	return std::min(nums[i], nums[j]);
}

double myPow2(double x, int n)
{
	if (abs(x - 1.0) < 0.000001)
		return 1.0;
	if (n == 1)
		return x;
	double a = x;
	int m = n % 2;
	a = myPow2(a, n/2);
	a = a * a;
	return m == 0 ? a : a*x;
}

double myPow(double x, int n) {
	if (n == 0)
		return 1.0;
	if (INT_MIN == n)
	{
		x = 1 / x;
		return myPow2(x, INT_MAX)*x;
	}
	if (n < 0)
	{
		return myPow2(1 / x, -n);
	} 
	
	else
	{
		return myPow2(x, n);
	}

}


int m2ain()
{
	vector<int> nums = {4,5,6,7,0, 1, 2 };
	cout << findMin(nums) << endl;
	cout << myPow(1.1, 5) << endl;
	getchar();
	return 0;
}