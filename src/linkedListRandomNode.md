[382. Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/)
==============================

原题
----

Given a singly linked list, return a random node's value from the
linked list. Each node must have the **same probability** of being
chosen.

**Follow up:**

What if the linked list is extremely large and its length is unknown
to you? Could you solve this efficiently without using extra space?

**Example:**

```
// Init a singly linked list [1,2,3].
ListNode head = new Listnode(1);
head.next = new Listnode(2);
head.next.next = new Listnode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
```

题意
----

给定一个单链表随机返回链表中节点的值。每个节点必须等可能的出现。

**跟进：**

如果链表足够大并且不知道长度应该如何做？能否不使用额外的空间高效的解决这个问题？

**示例：**

```
// Init a singly linked list [1,2,3].
ListNode head = new Listnode(1);
head.next = new Listnode(2);
head.next.next = new Listnode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
```

思路
----

参考[Cloudera Engineering Blog][]上面给出的Reservoir Sampling算法。最
简单的情况是链表中仅有一个元素，那么返回这个元素的概率为`1`；若链表中
有两个元素时，我们需要等可能的返回这两个元素中的一个，因此，可以随机生
成`[0, 1]`中的一个整数，若为`0`返回第一个元素，否在返回第二个元素；那
么有三个元素时，同理可以随机生成`[0, 2]`中的一个整数。但是由于我们不知
道链表的长度，因此不能通过上面的算法实现。但是在Reservoir Smpling算法
中利用了这个性质。当我们遍历链表时，第一个元素出现时，由于我们不知道其
后是否还有其他元素，因此先将该元素保存下来，若后续没有其他元素则返回该
值，若还包含后续元素，则遍历第二个元素，此时随机生成一个`[0,2]`的数，
我们需要保证第二个元素出现的概率为`1/2`，此时第一个元素的概率也为`1/2`。
当还有后续元素时，我们需要继续遍历，此时要保证第三个元素的概率为`1/3`，
从而第一个和第二个的概率分别为`1/2 * 2/3 = 1/3`，其中`1/2`是上一个选择
后遗留的概率，`2/3`是本轮不选择元素三的概率，因此，在长度为三的链表中，
可以随机生`[0,2]`的随机数，当为`0`时，返回第三个元素，否则返回前面保留
的值。当长度为`n`时，我们保证新到达的元素的概率为`1/n`，这就意味着我们
有`(n-1)/n`的概率选中之前我们保持的元素，由于之前保存的元素出现的概率
为`1/(n-1)`，因此，之前保存的元素的概率在此时的概率为`1/(n-1) *
(n-1)/n = 1/n`。

代码
----

```c++
class Solution {
public:
	Solution(ListNode *head) : head_(head) {
	}
	
	int getRandom() {
		ListNode *node = head_;
		int ret;
		
		for (int i = 1; node; ++i) {
			if (rand() % i == 0) {
				ret = node->val;
			}
			
			node = node->next;
		}
		
		return ret;
	}
	
private:
	ListNode *head_;
};
```

[Cloudera Engineering Blog]: http://blog.cloudera.com/blog/2013/04/hadoop-stratified-randosampling-algorithm/
