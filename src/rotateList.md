[61. Rotate List](https://leetcode.com/problems/rotate-list/)
=================

原题
----

Given a list, rotate the list to the right by *k* places, where *k* is
non-negative.

For example:

Gievn `1->2->3->4->5->NULL`, and *k=2*, return `4->5->1->2->3->NULL`.

思路
----

1. 利用两个指针找到需要右移的位置。假设指针`p,q`同时指向头节点，首先，
   利用指针`q`定位到`head`与`q`距离为`k`的节点，接着同时移动指针
   `p,q`直到`q->next`为`NULL`。此时，`p->next`所指向的节点就是移动后的
   头节点，把原来的头节点添加到链表尾部，即`q->next = head`。
   
代码
----

思路1示例代码
```c++
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL || head->next == NULL || k == 0) {
			return head;
		}
		
		k %= listLength(head); /* 避免右移时超出链表的长度 */
		if (k == 0) {
			return head;
		}
		
		ListNode *q = head;
		while (k--) {
			q = q->next;
		}
		
		ListNode *p = head;

		while (q->next != NULL) {
			p = p->next;
			q = q->next;
		}
		
		q->next = head;
		head = p->next;
		p->next = NULL;  /* 置空，否则会形成环 */
		
		return head;		
	}
	
	int listLength(ListNode* head) {
		int count = 0;
		while (head != NULL) {
			head = head->next;
			++count;
		}
		
		return count;
	}
};
```
