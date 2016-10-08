[19. Remove Nth Node From End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
======================================

原题
----

Given a linked list, remove the *n*th node from the end of list and return its head.

For example,

```
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
```

**Note:**

Given *n* will always be valid.

Try to do this in one pass.

思路
----

1. 两个指针。第一个指针首先步进*n*，若到达链表末尾，则直接返回头节点的
   下一个节点；否则同时步进两个指针，直到前一个到达链表末尾，删除后面
   指针所指的下一个节点。
   
代码
----

思路1示例代码
```c++
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *first, *last;
		
		first = last = head;
		while (n-- && first) {
			first = first->next;
		}
		
		if (first == NULL) {
			return head->next;
		}
		
		while (first->next != NULL) {
			last = last->next;
			first = first->next;
		}
		
		last->next = last->next->next;
		
		return head;
	}
};
```
