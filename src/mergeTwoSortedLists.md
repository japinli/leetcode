[21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)

原题
----

Merge two sorted linked lists and return it as a new list. The new
list should be made by splicing together the nodes of the first two
lists.

思路
----

1. 同时遍历两个链表，将两个链表中小的值加入到新的链表中，若其中一个链
   表为空时，将另一个链表加入到新链表之后。
   
代码
----

思路1示例代码
```c++
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode head(0);
		ListNode *p = &head;
		
		while (l1 && l2) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			} else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		
		p->next = l1 ? l1 : l2;
		
		return head.next;
	}
};
```
