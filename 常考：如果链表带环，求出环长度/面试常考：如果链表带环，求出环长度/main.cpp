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
		return slow;
	return nullptr;
}

int Cyclelen(ListNode* head)//求出环长度
{
	if(head == nullptr)
		return 0;
	if (head->next == nullptr)
		return 1;

	int len = 0;
	ListNode* meet_node = CheckCycle(head);
	if (meet_node == nullptr)
		return 0;

	ListNode* cur = meet_node->next;
	while (cur != meet_node)
	{
		cur = cur->next;
		++len;
	}
	return len;
}