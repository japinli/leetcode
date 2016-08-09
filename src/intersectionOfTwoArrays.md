[349. Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/)
=================================

原题
----

Given two arrays, write a function to compute their intersection.

**Example:**

Given nums1 = `[1, 2, 2, 1]`, nums2 = `[2, 2]`, return `[2]`.

**Note:**

* Each element in the result must be unique.
* The result can be in any order.

题意
----

给定两个数组，编写函数找出它们的交集。

**示例：**

给定数组`[1, 2, 2, 1]`和`[2, 2]`，返回`[2]`。

**注意：**

* 返回的结果中每个元素是唯一的。
* 返回的结果无顺序要求。

思路
----

1. 首先遍历一个数组建立一个集合，接着在遍历第二个数组，同时查看当前元
   素是否在集合中，若在集合中，则将其加入交集的集合中，遍历完之后返回
   交集集合中的元素。
2. 首先对数组去重，然后排序，接着同时遍历两个数组，比较元素大小，将相
   等的元素加入到返回的数组中，同时增加两个数组的索引，否则只增加小元
   素数组的索引，直到有一个数组结束为止。

代码
----

思路1示例代码
```C++
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> initSet;
		for (int i = 0; i < nums1.size(); ++i) {
			initSet.insert(nums1[i]);
		}
		
		set<int> resultSet;
		set<int>::const_iterator it;
		for (int i = 0; i < nums2.size(); ++i) {
			it = initSet.find(nums2[i]);
			if (it != initSet.end()) {
				resultSet.insert(nums2[i]);
			}
		}

		return vector<int>(resultSet.begin(), resultSet.end());
	}
};	
```

思路2示例代码
```C++
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		
		vector<int>::iterator vit;
		vit = unique(nums1.begin(), nums1.end());
		nums1.resize(distance(nums1.begin(), vit));		
		vit = unique(nums2.begin(), nums2.end());
		nums2.resize(distance(nums2.begin(), vit));
		
		
		
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
