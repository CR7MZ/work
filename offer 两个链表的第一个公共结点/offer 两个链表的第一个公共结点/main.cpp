//题目：https://www.nowcoder.com/questionTerminal/6ab1d9a29e88450685099d45c9e31e46?f=discussion
#include<iostream>
struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
//思路：
//1.因为两个链表第一个公共点之后就合并了。
//2.所以分别求出两链表的长度，让长的链表先走两长度只差
//3.最后一起走，直到相等。

int Listlen(ListNode* phead)//求每个链表的长度
{
	int count = 0;
	while (phead)
	{
		count++;
		phead=phead->next;
	}
	return count;
}
ListNode* firstwalk(ListNode* phead, int num)//长的链表先走num
{
	while (num--)
	{
		phead = phead->next;
	}
	return phead;
}
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == nullptr || pHead2 == nullptr)
		return nullptr;
	int count1 = Listlen(pHead1);
	int count2 = Listlen(pHead2);
	if (count1>count2)//长的先走
	{
		pHead1 = firstwalk(pHead1, count1 - count2);
	}
	else
	{
		pHead2 = firstwalk(pHead2, count2 - count1);
	}
	while (pHead1)//同时走
	{
		if (pHead1 == pHead2)
			return pHead1;
		pHead1 = pHead1->next;
		pHead2 = pHead2->next;
	}
	return nullptr;
}