[141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
======================

原题
----

Given a linked list, determine if it has a cycle in it.

**Follow up:**

Can you solve it without using extra space?

题意
----

给定一个链表，判断该链表是否存在环。

**跟进：**

能否不使用额外的空间完成此项任务？

思路
----

1. 利用集合解决该问题，链表中包含环，那至少有一个节点有两个前趋节点
   （首节点除外），通过遍历链表，同时判断集合中是否存在该节点，若不存
   在加入集合中，若已存在，说明链表存在环状结构。
2. 不使用额外空间，那么可以利用两个指针采用不同的步进值遍历链表（即快
   慢链表）的思想解决该问题，将原问题转化为追赶问题。设两个指针`p,q`同
   时从链表头开始移动，`p`每次步进`1`，`q`每次步进`2`，若链表中有环存
   在，则`p,q`指针总能在某个时刻相遇。

代码
----

思路1示例代码
```C++
class Solution {
public:
	bool hasCycle(ListNode *head) {
		set<ListNode *> nodeSet;
		set<ListNode *>::iterator it;
		
		while (head) {
			it = nodeSet.find(head);
			if (it == nodeSet.end()) {
				nodeSet.insert(head);
			} else {
				return true;
			}
			
			head = head->next;
		}
		
		return false;
	}
};
```

思路2示例代码
```C++
class Solution {
public:
	bool hasCycle(ListNode *head) {
		ListNode *slow = head;
		ListNode *fast = head;

		while (fast && fast->next) {
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
