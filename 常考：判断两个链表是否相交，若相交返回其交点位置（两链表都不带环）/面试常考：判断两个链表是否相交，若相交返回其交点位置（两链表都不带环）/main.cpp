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

//1.��������������һ�������ͬ�����ཻ��
//2.ͬʱ��Ҫͳ���������ȣ���ָ�򳤵�����ͷ��ָ�����߳���֮���λ�ã�֮��˫��һ���ߣ��������ǽ���
Node* HashCross(Node* head1,Node* head2)
{
	if (head1 == nullptr || head2 == nullptr)
		return nullptr;

	int num1 = 0, num2 = 0;
	Node* cur1 = head1;
	Node* cur2 = head2;

	while (cur1->next)
	{
		cur1 = cur1->next;
		++num1;
	}
	while (cur2->next)
	{
		cur2 = cur2->next;
		++num2;
	}

	if (cur1 != cur2)
		return nullptr;
	
	int tmp = 0;
	cur1 = head1;
	cur2 = head2;

	if (num1 > num2)
	{
		tmp = num1 - num2;
		while (tmp--)
		{
			cur1 = cur1->next;
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur1;
	}
	else
	{
		tmp = num2 - num1;
		while (tmp--)
		{
			cur2 = cur2->next;
		}
		while (cur1 != cur2)
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return cur2;
	}
}
