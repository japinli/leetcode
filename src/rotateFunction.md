[396. Rotate Function](https://leetcode.com/problems/rotate-function/)
======================

原题
----

Given an array of integers `A` and let *n* to be its length.

Assume `B_k` to be an array obtained by rotating the array `A` *k*
positions clock-wise, we define a "rotation function" `F` on `A` as
follow:

```
F(k) = 0 * B_k[0] + 1 * B_k[1] + ... + (n-1) * B_k[n-1]
```

Calculate the maximum value of `F(0), F(1), ..., F(n-1)`.

**Note:**

*n* is guaranteed to be less than `10^5`.

**Example:**

```
A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
```

思路
----

1. 遍历数组按给定的`F`求值，然后移动数组，重复求值过程，并找出其中的最
   大值。时间复杂度为`O(n^2)`。
2. 注意到在每次求值过程中，后一个数都是在前一个数的基础上加上所有位上
   数字的和，然后减去*n*倍移动的数得到的（时间复杂度为`O(n)`）。例如：
   
   ```
   A = [4, 3, 2, 6]，其中每位数字和为：4 + 3 + 2 + 6 = 15
   F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
   F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
   F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
   F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26
   
   F(0) --> F(1) = 25 + 15 - 4 * 6 = 16
   F(1) --> F(2) = 16 + 15 - 4 * 2 = 23
   F(2) --> F(3) = 23 + 15 - 4 * 3 = 26
   ```

代码
----

思路2示例代码
```c++
class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		int digitsSum = 0;
		int currentSum = F(A, digitsSum);
		int max = currentSum;
		size_t len = A.size();
		
		for (size_t i = 1; i < len; ++i) {
			currentSum += (digitsSum - len * A[len - i]);
			if (currentSum > max) {
				max = currentSum;
			}
		}
		
		return max;
	}
	
	int F(const vector<int>& A, int& digitsSum) {
		digitsSum = 0;
		int sum = 0;
		for (size_t i = 0; i < A.size(); ++i) {
			sum += i * A[i];
			digitsSum += A[i];
		}
		
		return sum;
	}
};
```
