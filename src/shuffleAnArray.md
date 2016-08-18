[384. Shuffle an Array](https://leetcode.com/problems/shuffle-an-array/)
=======================

原题
----

Shuffle a set of numbers without duplicates.

**Example:**

```
// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
```

题意
----

重洗一个无重复的整数集合。

**示例：**

```
// 初始化数组为 1, 2, 和 3。
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// 重洗数组 [1,2,3] 并返回其结果. 任何 [1,2,3] 的置换都是等可能的返回。
solution.shuffle();

// 重置数组为初始化的值 [1,2,3]。
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
```

思路
----

1. 通过Reservoir Smapling算法可以等可能的得到数组中的某个值，因此借助
   该思想我们可以通过遍历数组，每次返回一个值，随后将其删除，再次遍历
   直到数组为空为止。该算法的时间复杂度为`O(n^2)`。
2. [Knuth shuffle][]算法：该算法将长度为`n`的数组分为两个部分：剩余数
   组和结果数组。初始时剩余数组长度为`n`，结果数组长度为`0`。在第一轮
   选取中，随机选取区间`[0, n-1]`的数，并将其与`n-1`位置上的数交换，此
   时`n-1`位置的数是第一个选取的随机数，结果数组长度加`1`，剩余数组长
   度减`1`；接着进行第二轮选取，此时在区间`[0, n-2]`内随机选取一个数并
   与`n-2`位置上的数交换，结果数组长度加`1`，剩余数组长度减`1`。重复此
   过程直至剩余数组长度为`0`为止。此算法的时间复杂度为`O(n)`。
3. 方法2是一种*in-space*算法，在数组非常大时，这是它的一个优点。但是本
   题要保证能够重置为原数组，为此，通过使用额外的数据空间拷贝了一份原
   始数据，然后在这个拷贝的数据上进行操作。在*wikipedia*上给出的另
   *inside-out*算法，则动态的向数组添加元素，避免了先整体拷贝的操作。
   
代码
----

思路1示例代码
```c++
class Solution {
public:
	Solution(vector<int> nums) {
		array_ = nums;
	}
	
	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return array_;
	}
	
	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		list<int> tmp(array_.begin(), array_.end());
		list<int>::iterator it;
		vector<int> result;
		
		while (!tmp.empty()) {
			it = getRandom(tmp);
			result.push_back(*it);
			tmp.erase(it);
		}
		
		return result;
	}
	
	/** The paramter must be a reference type, because the return value
	 *  will be used at caller function.
	 */
	list<int>::iterator getRandom(list<int> &l) {
		list<int>::iterator rm, it;
		rm = it = l.begin();
		for (int i = 1; it != l.end(); ++it, ++i) {
			if (rand() % i == 0) {
				rm = it;
			}
		}
		
		return rm;
	}
	
private:
	vector<int> array_;
};
```

思路2示例代码
```c++
class Solution {
public:
	Solution(vector<int> nums) {
		array_ = nums;
	}
	
	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return array_;
	}
	
	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> result(array_);
		
		for (size_t i = result.size() - 1; i > 0 ; --i) {
			size_t idx = rand() % (i + 1);
			swap(result[idx], result[i]);
		}
		
		return result;
	}
	
private:
	vector<int> array_;
};
```

思路3示例代码
```c++
class Solution {
public:
	Solution(vector<int> nums) {
		array_ = nums;
	}
	
	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return array_;
	}
	
	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> result;
		
		for (size_t i = 0; i < array_.size(); ++i) {
			size_t len = result.size();
			size_t idx = rand() % (len + 1);
			if (idx == len) {
				result.push_back(array_[i]);
			} else {
				result.push_back(result[idx]);
				result[idx] = array_[i];
			}
		}
		
		return result;
	}
	
private:
	vector<int> array_;
};
```

[Knuth shuffle]: http://rosettacode.org/wiki/Knuth_shuffle
[Fisher-Yates shuffle]: https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
