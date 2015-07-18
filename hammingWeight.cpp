#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
using namespace std;

int hammingWeight(unsigned n)
{
	int result = 0;
	for (int i = 32; i > 0; i--)
	{
		if ((n << i & 0x80000000))
		{
			result++;
		}
	}
	return result;
}

int maixxxxn()
{
	unsigned n = 11;
	cout << hammingWeight(n) << endl;
	getchar();
	return 0;
}