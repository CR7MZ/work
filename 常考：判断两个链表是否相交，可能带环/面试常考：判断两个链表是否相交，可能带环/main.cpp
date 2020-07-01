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

Node* GetCycle(Node* head)//判断是否带环
{
	if (head == nullptr)
		return nullptr;

	Node* fast = head;
	Node* slow = head;

	while (fast != nullptr || fast->next != nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;
	}

	if (slow == fast)
		return slow;
	return nullptr;
}

Node* HashCrossY(Node* head1, Node* head2)//Y字相交法
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
//两个链表总共有三种情况，两个都不带环、都带环、一个带环一个不带环，那就要分开讨论。
//如果都不带环就是我们刚才所写的Y字相交法，如果一个带环一个不带环那么是不可能相交的。
//着重讨论一下两个都带环的。

Node* HasCross(Node* head1, Node* head2)
{
	if (!head1 || !head2)
		return false;

	Node* ret1 = GetCycle(head1);
	Node* ret2 = GetCycle(head2);

	if (ret1 == nullptr && ret2 == nullptr)//说明两个都不带环，使用Y字相交法
	{
		Node* node = HashCrossY(ret1, ret2);
	}
	else if ((ret1 == nullptr && ret2 != nullptr) || (ret2 == nullptr&& ret1 != nullptr))//一个带环一个不带环，说明不可能相交
	{
		return nullptr;
	}
	else //两个都带环
	{
		if (ret1->val == ret2->val)//交点在环外
		{
			int len1 = 0, len2 = 0;
			Node* cur1 = head1;
			Node* cur2 = head2;

			while(cur1 != ret1)
			{
				++len1;
				cur1 = cur1->next;
			}
			while (cur2 != ret2)
			{
				++len2;
				cur2 = cur2->next;
			}

			int tmp = 0;
			cur1 = head1;
			cur2 = head2;

			if (len1 > len2)
			{
				tmp = len1 - len2;
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
				tmp = len2 - len1;
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
		else//交点在环内
		{
			Node* re = ret1;
			while (re != ret2)
			{
				if (re->next == ret1) //遍历一圈发现没有相同的说明没有相交。
					return nullptr;
				re = re->next;
			}
			return ret2;
		}
	}
}