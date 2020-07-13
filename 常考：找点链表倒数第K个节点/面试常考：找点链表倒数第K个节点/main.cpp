#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x)
		:val(x)
		, next(nullptr)
	{}
};

ListNode* GetK(ListNode* head, int k)
{
	if (head == nullptr)
		return nullptr;

	ListNode* fast = head;
	ListNode* slow = head;
	int i = 0;
	while (fast)
	{
		fast = fast->next;
		if (i >= k)
		{
			slow = slow->next;
		}
		++i;
	}
	return slow;
}