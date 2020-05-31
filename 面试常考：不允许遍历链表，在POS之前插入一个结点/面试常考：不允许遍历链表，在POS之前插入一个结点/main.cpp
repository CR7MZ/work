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

void Func(Node* head,Node* pos,int x)//将结点插入pos后面，交换pos和pos下一个结点的值。
{
	if (head == nullptr)
		return;

	Node* node = new struct Node(x);
	node->next = pos->next;
	pos->next = node;
	swap(pos->val, node->val);
}