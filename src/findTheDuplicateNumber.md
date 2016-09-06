[287. Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)

原题
----

Given an array *nums* containing *n + 1* integers where each integer
between *1* and *n* (inclusive), prove that at least one duplicate
number must exist. Assume that there is only one duplicate number,
find the duplicate one.

**Note:**

1. You **must not** modify the array (assume the array is read only).
2. You must use only constant, *O(1)*extra space.
3. Your runtime complexity should be less than *O(n^2)*.
4. There is only one duplicate number in the array, but it could be
   repeated more than once.
   
思路
----

1. 最简单最容易想到的就是两次遍历，时间复杂度为*O(n^2)*不符合题目要求。
2. 数组中的数字只可能是`[1, n]`，且数组大小为`n+1`，因此数组中必定存在
   一个元素是重复的。因此可以将这个数组视为含环的单向链表，这样该问题
   就可以抽象为找单向链表环的入口点问题。解法类似于
   [Linked List Cycle II][]采用快慢指针实现。

代码
----

思路1示例代码（超时）
```c++
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		for (size_t i = 0; i < nums.size(); ++i) {
			for (size_t j = i + 1; j < nums.size(); ++j) {
				if (nums[i] == nums[j]) {
					return nums[i];
				}
			}
		}
		
		return -1;
	}
};
```

思路2示例代码
```C++
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = nums[0];
		int fast = nums[nums[0]];
		
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[nums[fast]];
		}
		
		fast = 0;
		while (slow != fast) {
			slow = nums[slow];
			fast = nums[fast];			
		}
		
		return slow;
	}
};
```

[Linked List Cycle II]: linkedListCycleII.md
