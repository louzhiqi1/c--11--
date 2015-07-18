#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
using namespace std;

int lengthoflastword(string s)
{
	if (s.length() == 0)
		return 0;
	int i = s.length() - 1;
	while (i>=0)
	{
		if (s[i] == ' ')
			i--;
		else
			break;
	}
	int j = i;
	while (i>=0)
	{
		if (s[i] == ' ')
			return j - i;
		else
			i--;
	}
	return j- i;
}

int maixn()
{
	string s("x fxx");
	cout << lengthoflastword(s) << endl;
	getchar();
	return 0;
}