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

void Func(Node* head,Node* pos,int x)//��������pos���棬����pos��pos��һ������ֵ��
{
	if (head == nullptr)
		return;

	Node* node = new struct Node(x);
	node->next = pos->next;
	pos->next = node;
	swap(pos->val, node->val);
}