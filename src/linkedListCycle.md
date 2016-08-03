141. Linked List Cycle
======================

原题
----
Given a linked list, determine if it has a cycle in it.

题意
----
给定一个链表，判断该链表是否存在环。

思路
----
使用两个指针采用不同的步进值遍历链表（即快慢链表）。每次步进时，慢指针步进1，快指针步进2，若链表中有环存在，则快指针总能在某个时刻等于慢指针。该问题是典型的追赶问题。

代码
----
```C++
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode *slow, *fast;
		
		slow = fast = head;
		while (slow && fast) {
			if (NULL == fast->next) {
				break;
			}
			
			slow = slow->next;
			fast = fast->next->next;
			
			if (slow == fast) {
				return true;
			}
		}
		
		return false;
	}
};
```
