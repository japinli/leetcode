[26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)
=========================================

原题
----

Given a sorted array, remove the duplicates in place such that each
element appear only *once* and return the new length.

Do not allocate extra space for another array, you must do this in
place with constant memory.

For example,

Given input array *nums* = `[1,1,2]`,

Your function should return length = `2`, with the first two elements
of *nums* being `1` and `2` respectively, It doesn't matter what you
leave beyond the new length.

思路
----

1. 由于数组已序，因此重复的元素必定连续，因此可以从左向右记录未重复的
   元素。例如：
   ```
   1 1 1 3 4 4 5
   
   1 3 4 5 4 4 5
   
   长度为 4 [1 3 4 5]
   ```
   
代码
----

思路1示例代码
```c++
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		size_t len = nums.size();
		if (len <= 1) {
			return len;
		}
		
		size_t newlen = 1;
		for (size_t i = 1; i < len; ++i) {
			if (nums[newlen - 1] != nums[i]) {
				nums[newlen++] = nums[i];
			}
		}
		
		return newlen;
	}
};
```
