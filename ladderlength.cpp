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
using namespace std;

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
	if (beginWord.length() != endWord.length())
		return 0;
	vector<string> dict;
	map<string, int> dist;
	dist[beginWord] = 1;
	dict.push_back(beginWord);
	while (!dict.empty()){
		string test = dict.front();
		dict.erase(dict.begin());
		string tmp = test;
		for (int i = 0; i < beginWord.size(); i++)
		{
			test = tmp;
			for (int j = 0; j < 26; j++)
			{
				test[i] = 'a' + j;
				if (test == endWord)
				{
					return dist[tmp] + 1;
				}
				if (wordDict.find(test) != wordDict.end() && dist[test] == 0)
				{
					dict.push_back(test);
					dist[test] = dist[tmp] + 1;
				}
			}
		}
	}
	return 0;
}
int mai3n()
{
	unordered_set<string> w = { "hot", "dot", "dog", "lot", "log" };
	string b = "hit", e = "cog";
	cout << ladderLength(b, e, w);
	getchar();
	return 0;
}