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

bool CheckCycle(ListNode* head)
{
	if (head == nullptr)
		return false;

	ListNode* fast = head;
	ListNode* slow = head;

	while (fast != nullptr || fast->next != nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (slow == fast)
			break;
	}

	if (fast == slow)
		return true;
	return false;
}