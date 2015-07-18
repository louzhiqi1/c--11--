#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <iterator>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
	ListNode *slow = head;
	ListNode *fast = slow;
	while (fast)
	{
		if (slow == NULL)
			return NULL;
		slow = slow->next;
		if (fast == NULL)
			return NULL;
		fast = fast->next;
		if (fast == NULL)
			return NULL;
		fast = fast->next;
		if (fast == slow)
		{
			fast = head;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
			}
			return fast;
		}
	}
	return NULL;
}