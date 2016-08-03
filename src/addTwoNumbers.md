[2. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)
====================

原题
----

You are given two linked lists representing two non-negative
numbers. The digits are stored in reverse order and each of their
nodes contain a single digit. Add the two numbers and return it as a
linked list.

**Input:** (2 -> 4 -> 3) + (5 -> 6 -> 4)

**Output:** 7 -> 0 -> 8

题意
----

给定两个链表表示的非负，每个节点包含一个数字并且以逆序的形式存储。将两
个链表中的数字相加并返回结果链表。

**输入：** (2 -> 4 -> 3) + (5 -> 6 -> 4)

**输出：** 7 -> 0 -> 8

即： 342 + 465 = 807

思路
----

遍历链表将每个节点的值相加，在相加时低位可能产生进位，同时每个节点只包
含数字`0~9`，因此最大值为`9 + 9 + 1 = 19`，故进位值为`0`或`1`。此外需
要注意链表的边界。

代码
----

```C++
class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode dummy(0);
		ListNode *p = l1, *q = l2, *curr = &dummy;
		int carry = 0;
		
		while (p || q) {
			int x = (p == NULL) ? 0 : p->val;
			int y = (q == NULL) ? 0 : q->val;
			int sum = x + y + carry;
			carry = sum / 10;
			curr->next = new ListNode(sum % 10);
			curr = curr->next;
			if (p) {
				p = p->next;
			}
			if (q) {
				q = q->next;
			}
		}
		if (carry) {
			curr->next = new ListNode(carry);
		}
		
		return dummy.next;
	}
};
```
