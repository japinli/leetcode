[31. Next Permutation](https://leetcode.com/problems/next-permutation/)
======================

原题
----

Implement next permutation, which rearranges numbers into the
lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the
lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its
corresponding outputs are in the right-hand column.

`1,2,3` → `1,3,2`
`3,2,1` → `1,2,3`
`1,1,5` → `1,5,1`

思路
----

1. 参考[sunnyChen18][]的思路。首先，从数组尾部遍历找出前一个元素小于后
   一个元素的位置，即`nums[i] < nums[i+1]`；接着继续从尾部插在第一个比
   `nums[i]`大的数，此时有两种情况：
   
   1. 若存在，则交换这两个数，并将`i+1`到末尾的数排序，即为所求序列；
   2. 若不存在，说明序列为降序排列，交换`i`与`len-1`，并对`i+1`到末尾
      的数排。
	  

代码
----

思路1示例代码
```c++
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1) {
			return;
		}
		
		if (len == 2) {
			swap(nums, 0, 1);
			return;
		}
		
		int i = len - 2;
		while (i > 0) {
			if (nums[i] < nums[i + 1]) {
				break;
			}
			i--;
		}
		
		int j = len - 1;
		while (j > i) {
			if (nums[j] > nums[i]) {
				break;
			}
			j--;
		}
		
		if (j != i) {
			swap(nums, i, j);
		} else {
			swap(nums, i, len - 1);
		}
		
		sort(nums.begin() + i + 1, nums.end());
	}
	
	void swap(vector<int>& nums, int i, int j) {
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
};
```
[sunnyChen18]: https://discuss.leetcode.com/topic/14124/sharing-my-clean-and-easy-understand-java-code-with-explanation
