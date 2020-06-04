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

Node* GetCycle(Node* head)//�ж��Ƿ����
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

Node* HashCrossY(Node* head1, Node* head2)//Y���ཻ��
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
//���������ܹ����������������������������������һ������һ�����������Ǿ�Ҫ�ֿ����ۡ�
//������������������Ǹղ���д��Y���ཻ�������һ������һ����������ô�ǲ������ཻ�ġ�
//��������һ�������������ġ�

Node* HasCross(Node* head1, Node* head2)
{
	if (!head1 || !head2)
		return false;

	Node* ret1 = GetCycle(head1);
	Node* ret2 = GetCycle(head2);

	if (ret1 == nullptr && ret2 == nullptr)//˵����������������ʹ��Y���ཻ��
	{
		Node* node = HashCrossY(ret1, ret2);
	}
	else if ((ret1 == nullptr && ret2 != nullptr) || (ret2 == nullptr&& ret1 != nullptr))//һ������һ����������˵���������ཻ
	{
		return nullptr;
	}
	else //����������
	{
		if (ret1->val == ret2->val)//�����ڻ���
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
		else//�����ڻ���
		{
			Node* re = ret1;
			while (re != ret2)
			{
				if (re->next == ret1) //����һȦ����û����ͬ��˵��û���ཻ��
					return nullptr;
				re = re->next;
			}
			return ret2;
		}
	}
}