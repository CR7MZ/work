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

Node* JosephCircle(Node*& head, size_t num)
{
	if (head == nullptr)
		return nullptr;

	Node* cur = head;
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = head;

	Node* tmp = nullptr;
	cur = head;
	while (1)
	{
		if (cur->next == cur)
			break;

		for (size_t i = 1; i < num; i++)
		{
			tmp = cur;
			cur = cur->next;
		}

		tmp->next = cur->next;
		delete cur;
		cur = tmp->next;
	}
	return cur;
}