[137. Single Number II](https://leetcode.com/problems/single-number-ii/)
=======================

原题
----

Given an array of integers, every element appears *three* times except
for one. Find that single one.

**Note:**

Your algorithm should have liner runtime complexity. Could you
implement it without using extra memory?

题意
----

给定整数数组，除一个元素仅出现一次外，其他每个元素都出现三次。找出只出
现一次的元素。

**注意：**

算法具有线性运行复杂度。能否不使用额外的空间完成？

思路
----

1. 同[Single Number][]。利用`hashmap`的方式实现，首先遍历数组记录每个
   元素出现的次数。然后遍历`hashmap`找出出现次数为`1`的元素。
2. 上述方法需要使用额外空间，题目给出的疑问指示该问题同样可以在不是用
   额外空间的前提下解决。注意到每个整数位在数组中出现的此数，例如有数
   组`[1,3,4,3,5,4,3,5,4,5]`，其二进制为
   `[0001, 0011, 0100, 0011, 0101, 0100, 0011, 0101, 0100, 0101]`，统
   计数组中每`bit`位出现`1`的个数为`0, 3, 3, 7`，取每位统计的个数模`3`，
   及得`1`的二进制位`0,0,0,1` 。该方法可以推广到出现`n`次的情况。

代码
----

思路1示例代码
```C++
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int, int> numsCount;
		
		for (int i = 0; i < nums.size(); ++i) {
			numsCount[nums[i]]++;
		}
		
		map<int, int>::const_iterator it;
		for (it = numsCount.begin(); it != numsCount.end(); ++it) {
			if (it->second == 1) {
				return it->first;
			}
		}
		
		return 0;
	}
};
```

思路2示例代码
```C++
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int bits = sizeof(int) * 8;
		int single = 0;
		
		for (int i = 0; i < bits; ++i) {
			int sum = 0;
			for (int j = 0; j < nums.size(); j++) {
				sum += (nums[j] >> i) & 0x01;
			}
			
			if (sum % 3) {
				single |= (1 << i);
			}
		}
		
		return single;
	}
};
```

[Single Number]: singleNumber.md
