#include <iostream>
using namespace std;

//��Ŀ��https://leetcode-cn.com/problems/insertion-sort-list/
//�������½�һ��������ʾ�Ѿ������������ͷ���Ϊnewhead��ÿ����ʹ��ԭ����headָ���Ԫ����newhead������ÿ��Ԫ�رȽ��ҵ����ʵ�λ��
//��ԭ������headָ��Ľ��ɾ�������������Ӧ��λ��

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* newhead = new ListNode(0);
		while (head){
			auto p = newhead;
			while (p->next && p->next->val < head->val) p = p->next;
			auto q = head;
			head = head->next;

			q->next = p->next;
			p->next = q;
		}
		return newhead->next;
	}

};