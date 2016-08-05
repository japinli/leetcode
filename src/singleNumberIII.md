[260. Single Number III](https://leetcode.com/problems/single-number-iii/)
========================

原题
----

Given an array of numbers `nums`, in which exactly two elements appear
only once and all other elements appear exactly twice. Find the two
elements that appear only once.

**For example:**

Given `nums = [1, 2, 1, 3, 2, 5]`, return `[3, 5]`.

**Note:**

1. The order of the result is not important. So in the above example,
   `[5, 3]` is also correct.
2. Your algorithm should run in liner runtime complexity. Could you
   implement it using only constant space complexity?
   
题意
----

给定一个整数数组`nums`，其中有两个元素仅出现一次，其他所有元素均出现两
次。找出仅出现一次的两个元素。

**例如：**

给定数组`nums = [1, 2, 1, 3, 2, 5]`，返回`[3, 5]`。

**注意：**

1. 返回元素的顺序不重要。例如上面的例子中返回`[5, 3]`也是正确的。
2. 线性时间复杂度。能否只用常量空间解决该问题？

思路
----

1. 利用`hashmap`，类似于[Single Number][]与[Single Number II][]。
2. 由于除了仅出现一次的元素外，其他元素均出现两次，那么通过异或就可以
   得到这两个元素的异或值。此后在遍历数组，根据异或值的某一位将数组区
   分为两个部分进行异或，求出仅出现一次的两个元素值。
   
代码
----

思路1示例代码
```C++
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> singleNums;
		map<int, int> numsCount;
		
		for (int i = 0; i < nums.size(); ++i) {
			numsCount[nums[i]]++;
		}
		
		map<int, int>::const_iterator it;
		for (it = numsCount.begin(); it != numsCount.end(); ++it) {
			if (it->second == 1) {
				singleNums.push_back(it->first);
			}
		}
		
		return singleNums;
	}
};
```

思路2示例代码
```C++
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int xorVal = 0;
		
		for (int i = 0; i < nums.size(); ++i) {
			xorVal ^= nums[i];
		}
		
		xorVal &= -xorVal;
		int single1 = 0, single2 = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] & xorVal) {
				single1 ^= nums[i];
			} else {
				single2 ^= nums[i];
			}
		}
		
		vector<int> singleNums;
		singleNums.push_back(single1);
		singleNums.push_back(single2);
		
		return singleNums;
	}
};
```

[Single Number]: singleNumber.md
[Single Number II]: singleNumberII.md
