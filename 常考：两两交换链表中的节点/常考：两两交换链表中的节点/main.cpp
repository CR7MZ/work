#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//题目：https://leetcode-cn.com/problems/swap-nodes-in-pairs/submissions/

//递归方式
//解析：递归的终止条件是链表中没有结点，或者链表中只有一个结点，此时无法进行交换。
//		如果链表中至少有两个或者两个以上的结点，那么两两交换之后，原链表中的头结点变为新的链表第二个结点
//		原链表中的第二个结点变为新链表的头结点。链表中其余结点可以两两交换递归实现。

//      用head表示原链表头结点，新链表的第二个结点。newhead表示原链表第二个结点，新链表的头结点

ListNode* swapPairs1(ListNode* head){
	if (head == nullptr || head->next == nullptr)
		return head;

	ListNode* newhead = head->next;
	head->next = swapPairs1(newhead->next);
	newhead->next = head;

	return newhead;
}

//迭代方式
//解析：https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/liang-liang-jiao-huan-lian-biao-zhong-de-jie-di-91/

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
