[371. Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/)
==========================

原题
----

Calculate the sum of two integers *a* and *b*, but you are **not
allowed** to use operator `+` and `-`.

**Example:**

Given *a=1* and *b=2*, return *3*.

思路
----

1. 在位运算中，异或操作等同于无进位加法，因此我们可以通过计算 *a* 和
   *b* 的异或值来计算其和，但是如何计算两数相加时，每个位上的进位值呢？
   通过观察可以发现与操作正好满足这种需求。因此，两个数的加法操作可以
   通过异或运算及与运算完成。

代码
----

思路1示例代码
```C++
class Solution {
public:
	int getSum(int a, int b) {
		int sum = 0, carry = 0;
		do {
			sum = a ^ b;
			carry = (a & b) << 1;
			a = sum;
			b = carry;
		} while (carry != 0);
		
		return sum;
	}
};
```
