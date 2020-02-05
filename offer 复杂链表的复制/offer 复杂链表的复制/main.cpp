//题目：https://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba?f=discussion
#include<iostream>
struct RandomListNode
{
	int label;
	struct RandomListNode* next;
	struct RandomListNode* random;
	RandomListNode(int x)
		:label(x)
		,next(nullptr)
		, random(nullptr)
	{}
};
//思路：分为三步
//1.复制每个结点，并将复制的结点放在原结点后面。（比如：复制A结点得到A1，将A1插入到A后面），这样就做是为了找到复制结点的指针域。
//2.遍历链表，将每个复制的结点的random指针域指向对应的其他复制结点。
//3.将链表分为原链表和复制链表。
RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;
	//第一步
	RandomListNode* cur = pHead;
	while (cur)
	{
		struct RandomListNode* node = new struct RandomListNode(cur->label);
		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}

	//第二步
	cur = pHead;
	while (cur)
	{
		RandomListNode* node = cur->next;
		if (cur->random)
			node->random = cur->random->next;
		cur = node->next;
	}

	//第三步
	RandomListNode* res = pHead->next;
	RandomListNode* tmp;
	cur = pHead;
	while (cur->next)
	{
		tmp = cur->next;
		cur->next = tmp->next;
		cur = tmp;
	}
	return res;
}