#include <iostream>
using namespace std;

//��Ŀ��https://www.nowcoder.com/questionTerminal/fc533c45b73a41b0b44ccba763f866ef?f=discussion
//1.����һ��ͷ��㣬��ֹԭ�����У���һ���͵ڶ�������е���ֵ��ͬ��
//2��������ָ��pre,las��pre���������û�г����ظ��Ľ�㣬las�൱�ڹ���ָ�룬����������˹��ظ��Ľ�㡣

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x)
		:val(x)
		, next(nullptr)
	{}
};

class Solution
{
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		ListNode* Head = new ListNode(0);
		Head->next = pHead;
		ListNode* pre = Head;
		ListNode* las = pHead;
		while (las)
		{
			if (las->next != NULL&&las->val == las->next->val)
			{
				while (las->next&&las->val == las->next->val)
					las = las->next;
				pre->next = las->next;
				las = las->next;
			}
			else
			{
				pre = pre->next;
				las = las->next;
			}
		}
		return Head->next;
	}
};