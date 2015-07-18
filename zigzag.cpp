#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

string convert(string s, int numRows) {
	if (numRows == 1 || s.length() < 3 || s.length() <= numRows)
		return s;
	else
	{
		string result;
		for (int l = 0; l < numRows; l++)
		{
			for (int j = l; j < s.length();)
			{
				result.push_back(s[j]);
				int cur = j + 2 * numRows - 2 - l * 2;
				if (s.length() > cur && cur != j)
				{
					j = cur;
					result.push_back(s[j]);
				}
				else
				{
					break;
				}
			}
		}
		return result;
	}
}

int test1()
{
	//string s("Apalindromeisaword, phrase, number, orothersequenceofunitsthatcanbereadthesamewayineitherdirection, withgeneralallowancesforadjustmentstopunctuationandworddividers.");
	string s("ABCDE");
	int num = 4;
	cout << convert(s, num) << endl;
	cout << convert(s, num).length() << " " << s.length() << endl;
	getchar();
	return 0;
}