[4. Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)
================================

原题
----

There are two sorted arrays **nums1** and **nums2** of size *m* and
*n* respectively.

Find the median of the two sorted arrays. The overall runtime
complexity should be *O(log(m+n))*.

**Example 1:**

```
nums1 = [1, 2]
nums2 = [2]

The median is 2.0
```

**Example 2:**

```
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

题意
----

两个已序数组**nums1** 和 **nums2**，其长度分别为*m,n*。找出两个数组中
的中位数。算法的时间复杂度应满足*O(log(m+n))*。

**示例1：**

```
nums1 = [1, 2]
nums2 = [2]

中位数为 2.0
```

**示例2：**

```
nums1 = [1, 2]
nums2 = [3, 4]

中位数为 (2 + 3)/2 = 2.5
```

思路
----

1. 合并两个数组，然后通过下标直接找出两个数组的中位数。此方法比较容易
   想到，其时间复杂度为线性时间不满足题中要求的*O(log(m+n))*。
2. 上面的思路是通过合并数组，然后在进行中位数的查找并计算。注意到我们
   只需要找到中位数的位置之后就不需要对后面的数据进行合并了，因此上述
   算法可以得以简化。但该算法最坏的情况下也同思路1一样。
3. 查找中位数可理解为寻找第`k`个元素。因此，可以借助查找`k`元素的思想
   将两个已序数组按照`k/2`分段。参考LeetCode上[vaputa][]与[MissMary][]
   的解题思路。
   
   例如按`k/2`将两个数组`A`和`B`进行分段如下所示：
   
   ```
   A[0], A[1], ..., A[k/2-1] | A[k/2], A[k/2+1], ..., A[m]
   B[0], B[1], ..., B[k/2-1] | B[k/2], B[k/2+1], ..., B[n]
   ```
   
   此时比较`A[k/2-1]`与`B[k/2-1]`，会有以下三种情况：
   
   * A[k/2-1] == B[k/2-1]
   * A[k/2-1] <  B[k/2-1]
   * A[k/2-1] >  B[k/2-1]
   
   当`A[k/2-1] < B[k/2-1]`时，我们可以得出由`A[0]...A[k/2-1]`不包含中
   位数，因此可以丢弃该部分值，同理`A[k/2-1] > B[k/2-1]`时，可以丢弃
   `B[0]...B[k/2-1]`的部分可以丢弃。当`A[k/2-1] == B[k/2-1]`时正好是中
   位数。

代码
----

思路1示例代码
```C++
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> mergedNums;
		int i = 0, j = 0;
		
		while (i < nums1.size() && j < nums2.size()) {
			if (nums1[i] < nums2[j]) {
				mergedNums.push_back(nums1[i++]);
			} else {
				mergedNums.push_back(nums2[j++]);
			}
		}
		
		while (i < nums1.size()) {
			mergedNums.push_back(nums1[i++]);
		}
		while (j < nums2.size()) {
			mergedNums.push_back(nums2[j++]);
		}
		
		int size = mergedNums.size();
		
		if (size & 0x01) {                  // odd, return the median directly
			return mergedNums[size >> 1];
		}
		
		// even, claculate the median then return
		return (mergedNums[size >> 1] + mergedNums[(size >> 1) - 1]) / 2.0;
	}
};
```

思路2示例代码
```C++
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size = nums1.size() + nums2.size();
		int k = size >> 1;
		int i = 0, j = 0;
		vector<int> mergedNums;
		
		while (k >= 0 && i < nums1.size() && j < nums2.size()) {
			if (nums1[i] < nums2[j]) {
				mergedNums.push_back(nums1[i++]);
			} else {
				mergedNums.push_back(nums2[j++]);
			}
			k--;
		}
		
		while (k >= 0 && i < nums1.size()) {
			mergedNums.push_back(nums1[i++]);
			k--
		}
		
		while (k >= 0 && j < nums2.size()) {
			mergedNums.push_back(nums2[j++]);
			k--;
		}
		
		if (size & 0x01) {
			return mergedNums.back();
		}
		
		return (mergedNums[size >> 1] + mergedNums[(size >> 1) - 1]) / 2.0;
	}
};
```

思路3示例代码
```C++
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		size_t len1 = nums1.size();
		size_t len2 = nums2.size();
		size_t total = len1 + len2;

		if (total & 0x01) {
			return findKth(nums1, 0, nums2, 0, (total >> 1) + 1);
		}
		
		double k1th = findKth(nums1, 0, nums2, 0, total >> 1);
		double k2th = findKth(nums1, 0, nums2, 0, (total >> 1) + 1);
		
		return (k1th + k2th) / 2.0;
	}

private:
	double findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k) {
		int len1 = nums1.size() - start1;
		int len2 = nums2.size() - start2;
		
		if (len1 > len2) {
			return findKth(nums2, start2, nums1, start1, k);
		}
		
		if (len1 == 0) {
			return nums2[start2 + k - 1];
		}
		
		if (k == 1) {
			return min(nums1[start1], nums2[start2]);
		}
		
		int skipA = min(k/2, len1);
		int skipB = min(k/2, len2);
		
		if (nums1[skipA + start1 - 1] < nums2[skipB + start2 - 1]) {
			return findKth(nums1, start1 + skipA, nums2, start2, k - skipA);
		}
		
		return findKth(nums1, start1, nums2, start2 + skipB, k - skipB);
	}
};	
```

[vaputa]: https://discuss.leetcode.com/topic/2778/share-my-simple-o-log-m-n-solution-for-your-reference
[MissMary]: https://discuss.leetcode.com/category/12/median-of-two-sorted-arrays
