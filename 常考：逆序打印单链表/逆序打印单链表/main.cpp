#include <iostream>
#include <stack>
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

void PrintListInReverse(Node* head)//�ݹ鷽ʽ
{
	if (head == nullptr)
		return;
	PrintListInReverse(head->next);
	cout << head->val << endl;
}
