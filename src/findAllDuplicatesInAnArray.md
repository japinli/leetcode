[442. Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/)
======================================

原题
----

Given an array of integers, `1 <= a[i] <= n` (*n* = size of array),
some elements appear **twice** and others appear **once**.

Find all the elements that appear **twice** in this array.

Could you do it without extra space and in `O(n)` runtime?

**Example:**

```
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
```

思路
----

1. 最容易想到的办法就是通过排序，然后遍历找出重复出现的元素，这种方法
   的时间复杂度依赖于排序算法的复杂度，通常为`O(n*lg n)`。
2. 思路1的方法虽然可行，但是不能满足题目对时间复杂度的要求。在思路1中，
   我们并没有充分利用到题目中给出的信息: 1.到元素`a[i]`只能在`[1,n]`之
   间取值；2.元素下标信息。3.重复元素只出现2次。利用这两点信息，我们可
   以将元素与其下标进行对应，这样重复的元素势必会与其下标存在不对应关
   系，且没有元素至多有一个重复元素，因此，在遍历时取出下标与元素不对
   应的即可。
   
代码
----

思路1示例代码

```c++
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		size_t size = nums.size();
		sort(nums.begin(), nums.end());
		int idx = 0;
		
		for (size_t i = 1; i < size; ++i) {
			if (nums[i] == nums[i - 1]) {
				nums[idx++] = nums[i];
			}
		}
		
		return vector<int>(nums.begin(), nums.begin() + idx);
	}
};
```

思路2示例代码

```c++
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		size_t size = nums.size();		
		size_t idx = 0;
		
		while (idx < size) {
			if (nums[idx] != nums[nums[idx] - 1]) {
				swap(nums[idx], nums[nums[idx] - 1]);
			} else {
				idx++;
			}
		}
		
		idx = 0;
		for (size_t i = 0; i < size; ++i) {
			if (i != nums[i] - 1) {
				nums[idx++] = nums[i];
			}
		}
		return vector<int>(nums.begin(), nums.begin() + idx);
	}
};
```
