#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
using namespace std;

int claim(int n){
	vector<int> steps;
	steps.resize(n+1);
	steps[1] = 1;
	steps[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		steps[i] = steps[i - 1] + steps[i - 2];
	}
	return steps[n];
}

int mazin()
{
	cout << claim(3) << endl;
	getchar();
	return 0;
}