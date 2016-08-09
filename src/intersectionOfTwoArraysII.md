[350. Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)
====================================

原题
----

Given two arrays, write a function to compute their intersection.

**Example:**

Given *nums1* = `[1, 2, 2, 1]`, *nums2* = `[2, 2]`, return `[2, 2]`.

**Note:**

* Each element in the result should appear as many times as it shows
  in both arrays.
* The result can be in any order.

**Follow up:**

* What if the given array is already sorted? How would you optimize
  your algorithm?
* What if *nums1*'s size is small compared to *nums2*'s size? Which
  algorithm is better?
* What if elements of *nums2* are stored on disk, and the memory is
  limited such that you cannot load all elements into the memory at
  once?
  
题意
----

给定两个数组，编写函数找出它们的交集。

**示例：**

给定数组`[1, 2, 2, 1]`和`[2, 2]`，返回`[2, 2]`。

**注意：**

* 返回的结果中每个元素出现的次数与其在两个数组中出现的次数一样多。
* 返回的结果无顺序要求。

**跟进：**

* 如果给定的数组已经是已序的？怎样优化你的算法？
* 如果*nums1*长度小于*nums2*的长度？那个算法更好？
* 如果*nums2*的元素存放在磁盘，并且不能一次全部加载到内存，应该怎样处理？

思路
----

1. 同[Intersection of Two Arrays][]的第二种思路，不删除重复元素。
2. 利用`hashmap`遍历其中一个数组，并记录每个数出现的次数，接着遍历第二
   个数组，查找是否在第一个数组中出现，并判断计数值。

思考
----

* 如果是已序的数组，则可以直接按照思路1的方式进行查找。
* 若*nums2*的元素不能全部加载到内存，可以利用思路2的思想，首先为其建立
  `hashmap`表。接着将*nums2*中的元素部分读入进行判断，在判断的过程中当
  `hashmap`中元素个数减为零时，移除该元素。最后`hashmap`为空或*nums2*
  遍历完时结束。

代码
----

思路1示例代码
```C++
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		
		int i = 0, j = 0;
		vector<int> result;
		while (i < nums1.size() && j < nums2.size()) {
			if (nums1[i] == nums2[j]) {
				result.push_back(nums1[i]);
				i++, j++;
			} else if (nums1[i] < nums2[j]) {
				i++;
			} else {
				j++;
			}
		}
		
		return result;
	}
};
```

思路2示例代码
```C++
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> dict;
		
		for (vector<int>::size_type i = 0; i < nums1.size(); ++i) {
			dict[nums1[i]]++;
		}
		
		vector<int> result;
		
		for (vector<int>::size_type i = 0; i < nums2.size(); ++i) {
			if (dict.find(nums2[i]) != dict.end() && dict[nums2[i]]-- > 0) {
				result.push_back(nums2[i]);
			}
		}
		
		return result;
	}
};
```

[Intersection of Two Arrays]: src/intersectionOfTwoArrays.md
