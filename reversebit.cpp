#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <bitset>
using namespace std;

unsigned reverseBits(unsigned n) {
	unsigned result = 0x0;
	for (int i = 32; i > 0; i--)
	{
		cout << bitset<sizeof(unsigned)*8>((((n << i) & 0x80000000) >> (31 - i))) << endl;
		result += ((((n << i) & 0x80000000) >> (31 - i)));
		//cout << hex << result << endl;
	}
		
	return result;
}

int maix2n()
{
	cout << reverseBits(2863311530) << endl;
	getchar();
	return 0;
}