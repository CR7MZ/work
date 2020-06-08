#include <iostream>
using namespace std;

struct Node
{
	int val;
	Node* next;
	Node(int x)
		:val(x)
		, next(nullptr)
	{}
};

void BubbleSort(Node*& head)
{
	if (head == nullptr)
		return;

	Node* count = head;
	Node* tail = nullptr;
	Node* cur = head;
	for (; count->next != nullptr; count = count->next)
	{
		for (cur = head ; cur->next != tail; cur = cur->next)
		{
			if (cur->val > cur->next->val)
			{
				swap(cur->val, cur->next->val);
			}
		}
		tail = cur;
	}
}