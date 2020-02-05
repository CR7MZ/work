//��Ŀ��https://www.nowcoder.com/questionTerminal/f836b2c43afc4b35ad6adc41ec941dba?f=discussion
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
//˼·����Ϊ����
//1.����ÿ����㣬�������ƵĽ�����ԭ�����档�����磺����A���õ�A1����A1���뵽A���棩������������Ϊ���ҵ����ƽ���ָ����
//2.����������ÿ�����ƵĽ���randomָ����ָ���Ӧ���������ƽ�㡣
//3.�������Ϊԭ����͸�������
RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;
	//��һ��
	RandomListNode* cur = pHead;
	while (cur)
	{
		struct RandomListNode* node = new struct RandomListNode(cur->label);
		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}

	//�ڶ���
	cur = pHead;
	while (cur)
	{
		RandomListNode* node = cur->next;
		if (cur->random)
			node->random = cur->random->next;
		cur = node->next;
	}

	//������
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