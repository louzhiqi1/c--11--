#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
#include <unordered_map>
#include <list>
using namespace std;

struct node{
	int key, val;
	node(int k, int v) :key(k), val(v){}
};

class LRUCache{
public:
	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		if (cacheMap.find(key) == cacheMap.end())
		{
			return -1;
		}
		else
		{
			mylist.splice(mylist.begin(), mylist, cacheMap[key]);
			cacheMap[key] = mylist.begin();
			return cacheMap[key]->val;
		}
	}

	void set(int key, int value) {
		if (cacheMap.find(key) == cacheMap.end())
		{
			if (mylist.size() == size)
			{
				node last = *(mylist.rbegin());
				cacheMap.erase(last.key);
				mylist.pop_back();
				mylist.push_front(node(key, value));
				cacheMap[key] = mylist.begin();
			}
			else
			{
				mylist.push_front(node(key, value));
				cacheMap[key] = mylist.begin();
			}
		}
		else
		{
			cacheMap[key]->val = value;
			mylist.splice(mylist.begin(), mylist, cacheMap[key]);
		}
	}
private:
	list<struct node> mylist;
	unordered_map<int, list<struct node>::iterator> cacheMap;
	int size;
};

int mxain()
{
	LRUCache l(2);
	/*for (int i = 0; i < 100; i++)
	{
		l.set(i, i * 2);
	}
	cout << "key = 3, val = " << l.get(3) << endl;

	cout << "key = 102, val = " << l.get(102) << endl;

	l.set(3, 2);
	cout << "key = 3, val = " << l.get(3) << endl;
	cout << "key = 133, val = " << l.get(3) << endl;*/

	l.set(2, 1);
	l.set(1, 1);
	l.set(2, 3);
	l.set(4, 1);

	cout << l.get(1) << " " << l.get(2) << endl;


	getchar();
	return 0;
}