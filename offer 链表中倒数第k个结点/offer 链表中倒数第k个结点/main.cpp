//��Ŀ��https://www.nowcoder.com/questionTerminal/529d3ae5a407492994ad2a246518148a?f=discussion
#include<iostream>
//˼·��
//��������ָ�룬��һ��ָ������k-1����Ȼ����ָ��ͬʱ����ߣ�ֱ�����ָ���nextָ����Ϊ�ա���ʱ����ָ��Ϊ������K���ڵ㡣
struct ListNode
{
	int val;
	struct ListNode* next;
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (k == 0 || pListHead == nullptr)//��һ���Ǳز����ٵģ������ж�����������������ͣ�һ��ҪҪ�ж�ͷ�ڵ��ǲ���Ϊ�գ�
		return nullptr;
	ListNode* slo = pListHead;
	ListNode* fas = pListHead;
	int n = k - 1;
	while (n)
	{
		if (fas->next != nullptr)//�п�������Ľڵ����С��K��Ҳһ��Ҫ�ж�һ�¡�
		{
			fas = fas->next;
			n--;
		}
		else                     //Ϊ�գ����ؿա�
			return nullptr;
	}
	while (fas->next)
	{
		slo = slo->next;
		fas = fas->next;
	}
	return slo;
}