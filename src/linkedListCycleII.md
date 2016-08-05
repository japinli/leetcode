[142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)
===========================

原题
----

Given a linked list, return the node where the cycle begins. If there
is no cycle, return `null`.

**Note:** Do not modify the linked list.

**Follow up:**

Can you solve it without using extra space?

题意
----

给定一个链表，如果链表中存在环，则返回环的起点。如果不存在环，则返回
`null`。

**注意：** 不要修改链表。

**跟进：**

能否不使用额外的空间完成此项任务？

思路
----

1. 要获取环状链表的起始节点，最为简单的方法就是遍历将链表时将节点指针
   存放到一直集合中，若集合中已存在该节点指针，则说明链表有环，且该节
   点既是环状链表的起点。否则，将该节点加入集合。此方法需要使用额外的
   空间。
2. 题目提出了不使用额外空间的要求，为了可以借用[Linked List Cycle][]中
   快慢指针的思想。
   1. `L1`定义为链表头节点到环入口点的节点数。
   2. `L2`定义为环入口点到相遇点的节点数。
   3. `C`定义为环中节点数。
   4. 由于快指针走的路径是慢指针的两倍，因此有`2(L1+L2)=L1+L2+n*C`，
      `n`是快指针在环中所走的圈数。从而`L1+L2=n*C => L1=(n-1)C+(C-L2)`。
   5. 从上可以总结出，当两个指针`p,q`分别从链表头和相遇点出发，每次步
      进`1`，当指针`p`走过`L1`长度时，指针`q`恰好移动`(n-1)C+(C-L2)`的
      距离，它们在环状节点的入口处相遇。
   
代码
----

思路1示例代码
```C++
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		set<ListNode *> nodeSet;
		set<ListNode *>::iterator it;
		
		while (head) {
			it = nodeSet.find(head);
			if (it == nodeSet.end()) {
				nodeSet.insert(head);
			} else {
				return head;
			}
			
			head = head->next;
		}
		
		return NULL;
	}
};
```

思路2示例代码
```C++
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return NULL;
		}
		
		ListNode *slow = head;
		ListNode *fast = head;
		ListNode *entry = head;
		
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {         // There is a cycle
				while (slow != entry) { // Find the entery pointer
					slow = slow->next;
					entry = entry->next;
				}
				return entry;
			}
		}
		
		return NULL;
	}
};
	
```

[Linked List Cycle]: linkedListCycle.md
