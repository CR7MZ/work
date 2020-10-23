#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//��Ŀ��https://leetcode-cn.com/problems/swap-nodes-in-pairs/submissions/

//�ݹ鷽ʽ
//�������ݹ����ֹ������������û�н�㣬����������ֻ��һ����㣬��ʱ�޷����н�����
//		������������������������������ϵĽ�㣬��ô��������֮��ԭ�����е�ͷ����Ϊ�µ�����ڶ������
//		ԭ�����еĵڶ�������Ϊ�������ͷ��㡣������������������������ݹ�ʵ�֡�

//      ��head��ʾԭ����ͷ��㣬������ĵڶ�����㡣newhead��ʾԭ����ڶ�����㣬�������ͷ���

ListNode* swapPairs1(ListNode* head){
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode* newhead = head->next;
	head->next = swapPairs1(newhead->next);
	newhead->next = head;

	return newhead;
}

//������ʽ
//������https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/liang-liang-jiao-huan-lian-biao-zhong-de-jie-di-91/

ListNode* swapPairs2(ListNode* head) {
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode* dump = new ListNode(-1);
	dump->next = head;
	ListNode* cur = dump;

	while (dump->next && dump->next->next){
		ListNode* node1 = dump->next;
		ListNode* node2 = dump->next->next;
		dump->next = node2;
		node1->next = node2->next;
		node2->next = node1;
		dump = node1;
	}
	return cur->next;
}
