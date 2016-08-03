[1. Two Sum](https://leetcode.com/problems/two-sum/)
============

原题
----

Given an array of integers, return **indices** of the two numbers such
that they add up to a specific target.

You may assume that each input would have **exactly** one solution.

**Example:**
```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

题意
----

给定一个整数数组，找到该数组中两个元素的和恰好等于指定数的值，返回其下标。

你可以假设每个指定的值都能在该数组中找到两个元素的和恰好等于该值。

**示例：**
```
给定 nums = [2, 7, 11, 15], target = 9,

因为 nums[0] + nums[1] = 2 + 7 = 9,
故返回 [0, 1].
```

**注意：** 题目中并未指出数组已经排序。

思路
----

1. 最容易想到的办法就是通过两重循环遍历，此种方法简单，但是效率低下，
   时间复杂度为O(n)。
2. 若是数组按递增（或递减）排序完成，则可以通过在数组两端同时向中间遍
   历查找，时间复杂度依赖于排序算法的时间复杂度。此外需要注意的时，在
   排序过程中会导致元素的下标发生变化，因此需要先保存元素的下标。

代码
----

思路1示例代码
```C++
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ret;
		int len = nums.size();
		for (int i = 0; i < len; ++i) {
			for (int j = len - 1; j > i; --j) {
				if (nums[i] + nums[j] == target) {
					ret.push_back(i);
					ret.push_back(j);
					return ret;
				}
			}
		}
		
		return ret;
	}
};
```

思路2示例代码
```C++
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<idx> tmp;
		vector<int> ret;
		int len = nums.size();
		for (int i = 0; i < len; ++i) {
			idx t;
			t.index = i;
			t.value = nums[i];
			tmp.push_back(t);
		}
		
		sort(tmp.begin(), tmp.end(), cmp);
		
		int i = 0, j = len - 1;
		while (i < j) {
			int sum = tmp[i].value + tmp[j].value;
			if (sum == target) {
			ret.push_back(tmp[i].index);
			ret.push_back(tmp[j].index);
			break;
		}
		if (sum < target) {
			i++;
		} else {
			j--;
		}
	}
	
	return ret;
	}

private:
	struct idx {
		int index;
		int value;
	};
	struct compare {
		bool operator()(idx x, idx y) {
			return x.value < y.value;
		}
	} cmp;	
};
```
