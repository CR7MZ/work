#include<iostream>
using namespace std;
//https://www.nowcoder.com/questionTerminal/75e878df47f24fdc9dc3e400ec6058ca


class solution
{
public:
	ListNode* ReverseList(ListNode* pHead) {//����1����ͷ�����ÿ���ڵ����β嵽ͷ���ǰ�棬���������ת
		if (pHead == nullptr)
			return nullptr;
		ListNode* head = pHead;//��ָ�� ÿ����ǰ����ڵ���ͷ��㡣
		ListNode* tmp = head->next;//��ָ�� ÿ��Ҫ�����뵽ǰ��Ľڵ�
		ListNode* old = pHead;//��ָ�� ʼ��ָ���ʼ�Ľڵ�
		while (tmp)//��tmpΪ�գ�˵������ת����
		{
			old->next = tmp->next;//��Ҫǰ��Ľڵ�tmp���������з���
			tmp->next = head;//��tmp�ڵ�嵽ͷǰ�棬tmp��Ϊ�µ�ͷ
			head = tmp;//��ʱͷ��Ϊtmp�ڵ�
			tmp = old->next;//tmp�ص�����ڵ����һ���������������
		}
		return head;
	}

	ListNode* ReverseList(ListNode* pHead)//����2���ı�����ÿ���ڵ��ָ��ʹ��ֱ�ӷ�ת
	{
		ListNode *pre = *pphead;   //��ִ�в�����ǰһ���ڵ�
		ListNode *cur = pre->next; //��ִ�в����Ľڵ�
		ListNode *next = cur;      //��ִ�в����ĺ�һ���ڵ㣬��ʱָ��cur����ѭ����ʼ��ʱ����ת�����һ���ڵ�

		pre->next = NULL; //��ʱ��ͷ��������ת�����β������������������β�ڵ�
		while (next)
		{
			next = next->next; //����next�����һ���ڵ㣬֮���Բ������������Ϊ�����������������ڵ��޷����в�����
			cur->next = pre; //��ԭ��ָ�ź����ָ��ǰ�������Ⱥ�ת��
			pre = cur; //Ϊ���´�ѭ�����������ݣ������������´�ѭ������һ���ڵ㣨����ִ�в����Ľڵ㽫����´�ѭ������һ���ڵ㣩
			cur = next; //ͬ�ϣ����ε���һ���ڵ㽫���Ϊ�´εı�ִ�нڵ㣩
		}

		return pre; //ѭ��������cur��next���Ѿ�ָ����ˣ�pre�����µ�ͷ
	}
};