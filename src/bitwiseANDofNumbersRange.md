[201. Bitwise AND of Numbers Range](https://leetcode.com/problems/bitwise-and-of-numbers-range/)
===================================

原题
----

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the
bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

题意
----

给定一个区间`[m, n]`，其中`0 <= m <= n <= 2147483647`，计算区间内所有
元素按位与的值，包括起始点。

例如，给定区间`[5, 7]`，程序应返回`4`。

思路
----

1. 思路比较简单，遍历整个区间，计算按位与的值返回。当区间中出现`0`时或
   中间结果出现`0`时，此时无论后续包含何种数字，按位与结果都为`0`，因
   此直接返回。此方法的时间复杂度为O(n)，LeetCode提交超时。

2. 利用`2`的幂的性质。

   a. 一个数为`2`的幂，则其二进制位仅包含一个`1`。
   b. 任何小于`2`的幂的数（除零外）与其进行`&`操作都为该数。
   
   利用上述性质，按如下步骤求解该问题：
   
   a. 找出区间中最大且为`2`的幂的数。
   b. 若存在且该值大于`m`，可知区间各值`&`操作的结果为`0`，直接返回。
   c. 若存在且该值等于`m`，则区间各值`&`操作的结果为此数，直接返回。
   c. 若不存在，遍历区间`[m, n]`并计算`&`操作的结果，返回。
   
   注意：在遍历时可能会存在溢出情况，因此遍历的变量应采用无符号数。

代码
----

思路2示例代码
```C++
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int shift = 0;
		int power;
		
		while ((power = (0x40000000 >> shift)) > n) {
			shift++;
		}
		
		if (power == m) {
			return m;
		} else if (power > m) {
			return 0;
		}
		
		int ret = 0xFFFFFFFF;
		for (size_t i = m; i <= n; ++i) {
			ret &= i;
		}
		
		return ret;
	}
};
```
