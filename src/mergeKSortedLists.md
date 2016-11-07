[23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)
==========================

原题
----

Merge *k* sorted linked lists and return it as one sorted
list. Analyze and describe its complexity.

思路
----

1. 遍历 *k* 个链表并合并其中的元素，若链表的平均长度为 *n* ，那么合并
   *k* 个链表的时间复杂度为`O(kn)`。
2. 通过将 *k* 个链表的非空首元素存放在一个最小堆中，在堆中元素的插入只
   需要 `O(lg k)` 的时间复杂度。因此整体时间复杂度为 `O(n * lg k)`。
   
代码
----

思路1示例代码

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		size_t size = lists.size();
		if (size < 1) {
			return NULL;
		} else if (size == 1) {
			return lists[0];
		}
		
		for (size_t i = 1; i < size; ++i) {
			lists[0] = mergeLists(lists[0], lists[i]);
		}
		
		return lists[0];
	}
	
	ListNode* mergeLists(ListNode* list1, ListNode* list2) {
		if (list1 == NULL || list2 == NULL) {
			return list1 == NULL ? list2 : list1;
		}
		
		ListNode head(0);
		ListNode *p = &head;
		
		while (list1 && list2) {
			if (list1->val < list2->val) {
				p->next = list1;
				list1 = list1->next;
			} else {
				p->next = list2;
				list2 = list2->next;
			}
			p = p->next;
		}
		
		if (list1) {
			p->next = list1;
		}
		if (list2) {
			p->next = list2;
		}
		
		return head.next;
	}
};
```

思路2示例代码

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		struct cmp {
			bool operator() (ListNode* l1, ListNode* l2) {
				return l1->val > l2->val;
			}
		};
		
		priority_queue<ListNode*, vector<ListNode*>, cmp> min_heap;
		for (size_t i = 0; i < lists.size(); ++i) {
			if (lists[i]) {
				min_heap.push(lists[i]);
			}
		}
		
		ListNode head(0);
		ListNode *p = &head;
		
		while (!min_heap.empty()) {
			ListNode* min = min_heap.top();
			min_heap.pop();
			
			p->next = min;
			p = p->next;
			
			if (min->next) {
				min_heap.push(min->next);
			}
		}
		
		return head.next;
	}
};
 ```
