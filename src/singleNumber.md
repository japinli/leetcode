[136. Single Number](https://leetcode.com/problems/single-number/)
====================

原题
----

Given an array of integers, every element appears *twice* except for
one. Find that single one.

**Note:**

Your algorithm should have liner runtime complexity. Could you
implement it without using extra memory?

题意
----

给定整数数组，除一个元素仅出现一次外，其他每个元素都出现两次。找出只出
现一次的元素。

**注意：**

算法具有线性运行复杂度。能否不使用额外的空间完成？

思路
----

1. 要具有线性时间，可以利用`hashmap`的方式实现，首先遍历数组记录每个元
   素出现的次数。然后遍历`hashmap`找出出现次数为`1`的元素。
2. 题目指出不使用额外空间解决此问题，因此，上述解决方案不是最理想的。
   注意到题目中明确指出数组中仅有一个元素出现一次，其他元素均出现两次，
   而不是三次。由于一个数异或自身为零，因此，可以通过异或操作解决此问
   题。只要是其他元素出现的次数是偶数次，都可以通过这种方法解决。
3. 该问题也可以通过先对数组排序，然后遍历数组找出仅出现一次的元素。但
   是基于比较的排序算法时间复杂度最低也为*O(nlgn)*，无法满足线性时间。
   计数排序、桶排序以及基数排序则可以提供线性时间的排序，不过对数据的
   依赖比较强。
   
代码
----

思路1示例代码
```C++
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		map<int, int> numsCount;
		
		for (int i = 0; i < nums.size(); ++i) {
			numsCount[nums[i]]++;    // The second element setted zero by default
		}
		
		for (map<int, int>::iterator it = numsCount.begin();
		     it != numsCount.end(); 
			 ++it) {
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
		int single = 0;
		
		for (int i = 0; i < nums.size(); ++i) {
			single ^= nums[i];
		}
		
		return single;
	}
};
```
