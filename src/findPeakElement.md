162. Find Peak Element
======================

原题
----

A peak element is an element that is greater than its neighbors.

Given an input array where $$num[i] \neq num[i+1]$$, find a peak
element and return its index.

The array may contain multiple peaks, in that case return the index to
any one of the peaks is fine.

You may imagine that $$num[-1] = num[n] = -\infty$$.

For example, in array $$[1, 2, 3, 1]$$, 3 is a peak element and your
function should return the index number 2.

题意
----
峰值是大于它周围的元素的值。
给定数组num，且满足num[i]不等于num[i+1]，找出该数组中的峰值并返回其下标。
数组可能包含多个峰值，此时返回其中任何一个峰值的下标即可。
你可以假设num[-1]和num[n]为负无穷大。
示例：数组[1, 2, 3, 1]中，3是该数组的峰值，你需要返回其下标2。

思路
----
1. 从第一个元素开始，判断它左右的两个元素是否小于该元素，若小于则返回，否则判断下一个元素。此方法中需要注意首尾元素的特殊情况，为避免可以采用辅助空间额外添加两个元素（哨兵），方便其判断。
2. 利用二分查找的思想，首先在判断数组中部的元素是否为峰值，若是直接返回其下标，否则将在大于中部元素的区间继续执行该操作。

代码
----
```C++
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		vector<int> tmp;
		
		tmp.push_back(nums[0]);
		for (int i = 0; i < nums.size(); i++) {
			tmp.push_back(nums[i]);
		}
		tmp.push_back(nums[nums.size()-1]);
		
		int idx = 1;
		for (/* void */; idx < tmp.size(); idx++) {
			if (tmp[idx] >= tmp[idex - 1] && tmp[idx] > tmp[idx + 1]) {
				break;
			}
		}
		
		return idx - 1;
	}
};
```

```C++
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int high, low;
		high = nums.size() - 1, low = 0;
		
		while (low + 1 < high) {
			int mid = low + (high - low) / 2;
			if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
				return mid;
			} else if (nums[mid] > nums[mid - 1]) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		
		if (nums[low] > nums[high]) {
			return low;
		}
		
		return high;
	}
};
```
