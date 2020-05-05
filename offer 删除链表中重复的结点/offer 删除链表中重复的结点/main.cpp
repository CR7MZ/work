#include <iostream>
using namespace std;

//题目：https://www.nowcoder.com/questionTerminal/fc533c45b73a41b0b44ccba763f866ef?f=discussion
//1.增加一个头结点，防止原链表中，第一个和第二个结点中的数值相同。
//2定义两个指针pre,las。pre：用来标记没有出现重复的结点，las相当于工作指针，向后搜索，滤过重复的结点。

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