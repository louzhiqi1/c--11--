/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		addTwoEx(l1, l2, 0);
	}
	ListNode* addTwoEx(ListNode* l1, ListNode* l2, int add)
	{
		if (l1 == NULL)
		{
			if (add != 0)
			{
				ListNode *ptr = (ListNode*)malloc(sizeof(ListNode));
				ptr->val = add;
				ptr->next = NULL;
				return addTwoEx(ptr, l2, 0);
			}
			else
				return l2;
		}
		else if(l2 == NULL)
		{
			if (add != 0)
			{
				ListNode *ptr = (ListNode*)malloc(sizeof(ListNode));
				ptr->val = add;
				ptr->next = NULL;
				return addTwoEx(l1, ptr, 0);
			}
			else
				return l1;
		}
		else
		{
			ListNode *ptr = (ListNode*)malloc(sizeof(ListNode));
			ptr->val = l1->val + l2->val + add;
			add = ptr->val / 10;
			ptr->val %= 10;
			ptr->next = addTwoEx(l1->next, l2->next, add);
			return ptr;
		}
	}

};