#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int lengthOfLongestSubstring(string s) {
	int maxnum = 0;
	for (int i = 0, j = 0; i < s.length(); i ++)
	{
		bool charset[255] = { false };
		j = i;
		while(!charset[s[j]] && j < s.length())
		{
			charset[s[j]] = true;
			j++;
		}
		maxnum = max(j - i, maxnum);
		
	}
	return maxnum;
}
int ggg()
{
	string s("abb");
	cout << lengthOfLongestSubstring(s);
	getchar();
	return 0;
}