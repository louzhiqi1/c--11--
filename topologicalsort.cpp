#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
#include <list>
using namespace std;
class sulotion{
public:
	void dfs_fuck(map<int, vector<int>>::iterator &i, map<int, int> &visit, map<int, vector<int>>& e, vector<int>& result)
	{
		if (visit.size() == e.size())
			return;
		visit[i->first] = 1;
		for (vector<int>::size_type j = 0; j < i->second.size(); j++)
		{
			if (visit[i->second[j]] == 0)
			{
				map<int, vector<int>>::iterator shit = e.find(i->second[j]);
				dfs_fuck(shit, visit, e, result);
			}
		}
		result.push_back(i->first);
	}
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> result, v;
		map<int, vector<int>> e;
		for (vector<pair<int, int>>::size_type i = 0; i < prerequisites.size(); i++)
		{
			if (e.find(prerequisites[i].second) == e.end())
			{
				vector<int> n;
				n.push_back(prerequisites[i].first);
				e[prerequisites[i].second] = n;
			}
			else
			{
				if (e.find(prerequisites[i].first) == e.end())
				{
					e[prerequisites[i].second].push_back(prerequisites[i].first);
					vector<int> n;
					e[prerequisites[i].first] = n;
				}
				else
				{
					for (vector<int>::size_type j = 0; j < e[prerequisites[i].first].size(); j++)
					{
						if (e[prerequisites[i].first][j] == prerequisites[i].second)
						{
							return v;
						}
					}
				}
			}
			if (e.find(prerequisites[i].first) == e.end())
			{
				vector<int> n;
				e[prerequisites[i].first] = n;
			}
		}
		map<int, int> visit;
		for (map<int, vector<int>>::iterator i = e.begin(); i != e.end(); i++)
		{
			if (visit.size() == e.size())
				break;
			// 没有遍历过
			dfs_fuck(i, visit, e, result);
		}
		for (int i = 0; i < result.size() / 2; i++)
			std::swap(result[i], result[result.size() - 1 - i]);
		return result;
	}
};



int main()
{
	vector<pair<int, int>> prerequisites;
	pair<int, int> a(1, 2), b(2, 3), c(3,4), d(4, 5);
	prerequisites.push_back(a);
	prerequisites.push_back(b);
	prerequisites.push_back(c);
	prerequisites.push_back(d);
	sulotion s;
	vector<int> result = s.findOrder(5, prerequisites);
	for (auto i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	getchar();
	return 0;
}
