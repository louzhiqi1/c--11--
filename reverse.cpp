#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
using namespace std;
int reverse2(int x);
int reverse(int x){
	if (x > 0)
		return reverse2(x);
	else if (x == 0 || x== INT_MIN)
		return 0;
	else
		return -reverse2(abs(x));
}
int reverse2(int x)
{
	string s;
	while (true)
	{
		char a = x % 10;
		s.push_back(a);
		if (x < 10)
			break;
		else
			x = x / 10;
		
	}
	long long x2 = 0ll;
	for (string::iterator itr = s.begin(); itr != s.end(); itr++)
	{
		x2 = x2* 10 + *itr;
	}
	if (x2 > 2147483648)
		x = 0;
	else
		x = (int)x2;
	return x;
}

int rrr()
{
	cout << reverse(INT_MIN);
	getchar();
	return 0;
}