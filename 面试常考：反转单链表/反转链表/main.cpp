#include<iostream>
using namespace std;
//https://www.nowcoder.com/questionTerminal/75e878df47f24fdc9dc3e400ec6058ca


class solution
{
public:
	ListNode* ReverseList(ListNode* pHead) {//方法1：将头结点后的每个节点依次插到头结点前面，以完成链表反转
		if (pHead == nullptr)
			return nullptr;
		ListNode* head = pHead;//此指针 每次向前插入节点后的头结点。
		ListNode* tmp = head->next;//此指针 每次要被插入到前面的节点
		ListNode* old = pHead;//此指针 始终指向最开始的节点
		while (tmp)//当tmp为空，说明链表反转结束
		{
			old->next = tmp->next;//将要前插的节点tmp，从链表中分离
			tmp->next = head;//将tmp节点插到头前面，tmp成为新的头
			head = tmp;//此时头变为tmp节点
			tmp = old->next;//tmp回到最初节点的下一个，继续上面操作
		}
		return head;
	}

	ListNode* ReverseList(ListNode* pHead)//方法2：改变链表每个节点的指向。使其直接翻转
	{
		ListNode *pre = *pphead;   //被执行操作的前一个节点
		ListNode *cur = pre->next; //被执行操作的节点
		ListNode *next = cur;      //被执行操作的后一个节点，暂时指在cur，在循环开始的时候跳转到其后一个节点

		pre->next = NULL; //此时的头，将会是转换后的尾，这里是在设置链表尾节点
		while (next)
		{
			next = next->next; //先让next变成下一个节点，之所以不放在最后，是因为放在最后则最后两个节点无法进行操作。
			cur->next = pre; //让原本指着后面的指到前面来（先后转）
			pre = cur; //为了下次循环而传递数据，这里是设置下次循环的上一个节点（本次执行操作的节点将会成下次循环的上一个节点）
			cur = next; //同上（本次的下一个节点将会成为下次的被执行节点）
		}

		return pre; //循环跳出后cur和next都已经指向空了，pre才是新的头
	}
};