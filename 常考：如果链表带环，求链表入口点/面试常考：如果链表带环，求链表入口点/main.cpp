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

ListNode* CheckCycle(ListNode* head)
{
	if (head == nullptr)
		return nullptr;

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
		return slow;
	return nullptr;
}

ListNode* GetCycleEntry(ListNode* head)
{
	if (head == nullptr)
		return nullptr;
	if (head->next == nullptr)
		return nullptr;

	ListNode* meet_node = CheckCycle(head);
	if (meet_node == nullptr)
		return nullptr;

	ListNode* cur = head;
	while (cur != meet_node)
	{
		cur = cur->next;
		meet_node = meet_node->next;
	}
	return cur;
}