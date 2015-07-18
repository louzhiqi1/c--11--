#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
using namespace std;
int calc(int i, int j, int heighti, int heightj)
{
	return (j - i)*min(heighti, heightj);
}
int container(vector<int> height)
{
	int maxsq = 0;
	for (int i = 0, j = height.size() - 1; i < j;)
	{	
		maxsq = max(calc(i, j, height[i], height[j]), maxsq);
		if (height[i] < height[j])
		{
			int k = i;
			while (k < j && height[k] <= height[i])
				k++;
			i = k;
		}
		else
		{
			int k = j;
			while (k > i&&height[k] <= height[j])
				k--;
			j = k;
		}
	}
	return maxsq;
}


int xxx()
{
	vector<int> height = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	cout << container(height);
	getchar();
	return 0;
}
