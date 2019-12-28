//题目：https://www.nowcoder.com/questionTerminal/529d3ae5a407492994ad2a246518148a?f=discussion
#include<iostream>
//思路：
//定义两个指针，让一个指针先走k-1步，然后两指针同时向后走，直到快的指针的next指针域为空。此时慢的指针为倒数第K个节点。
struct ListNode
{
	int val;
	struct ListNode* next;
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (k == 0 || pListHead == nullptr)//这一步是必不可少的，必须判定。（做链表类的题型，一定要要判定头节点是不是为空）
		return nullptr;
	ListNode* slo = pListHead;
	ListNode* fas = pListHead;
	int n = k - 1;
	while (n)
	{
		if (fas->next != nullptr)//有可能链表的节点个数小于K。也一定要判定一下。
		{
			fas = fas->next;
			n--;
		}
		else                     //为空，返回空。
			return nullptr;
	}
	while (fas->next)
	{
		slo = slo->next;
		fas = fas->next;
	}
	return slo;
}