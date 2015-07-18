#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
using namespace std;

bool isHappy(int n) {
	vector<int> nums;
	map<int, bool>  dict;
	while (n != 1 && dict.find(n) == dict.end())
	{
		dict[n] = true;
		nums.clear();
		while (n)
		{
			int tmp = n - n / 10 * 10;
			n = n / 10;
			nums.push_back(tmp);
		}

		for (int i = 0; i < nums.size(); i++)
		{
			n += nums[i] * nums[i];
		}
	}
	return n == 1;
}

int maiddn()
{
	int a;
	cin >> a;
	cout << isHappy(a) << endl;
	getchar();
	return 0;
}