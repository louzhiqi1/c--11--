#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
using namespace std;

string addbinary(string a, string b)
{
	if (a.size() > b.size())
		return addbinary(b, a);
	string result(max(a.size(), b.size())+1,'0');
	char tmp = '0';
	for (int i = a.size()-1, j = b.size()-1 ; i >= 0; i--, j--)
	{
		if (a[i] == b[j] && a[i] == '1')
		{
			if (tmp == '1')
			{
				result[j + 1] = '1';
			}
			else
			{
				result[j+1] = '0';
				tmp = '1';
			}
		}
		else if (a[i] != b[j])
		{
			if (tmp == '1')
			{
				result[j + 1] = '0';
			}
			else
			{
				result[j + 1] = '1';
				tmp = '0';
			}
		}
		else
		{
			if (tmp == '1')
			{
				result[j + 1] = '1';
				tmp = '0';
			}
			else
			{
				result[j + 1] = '0';
			}
		}
	}
	for (int i = b.size()-a.size()-1 ; i >=0 ; i -- )
	{
		if (b[i] == '1' && tmp == '1')
			result[i + 1] = '0';
		else if (b[i] != tmp)
		{
			result[i + 1] = '1';
			tmp = '0';
		}
		else
		{
			result[i + 1] = '0';
		}
	}
	
	if (tmp == '1')
	{
		result[0] = '1';
		return result;
	}
	else
	{
		string result2(result.begin() + 1, result.end());
		return result2;
	}
}

int madddin()
{
	string a = "100";
	string b = "110010";
	cout << addbinary(a, b) << endl;
	getchar();
	return 0;
}