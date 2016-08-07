[7. Reverse Integer](https://leetcode.com/problems/reverse-integer/)
====================

原题
----

Reverse digits of an integer.

**Example1:** x = 123, return 321

**Example2:** x = -123, return -321

**Have you thought about this?**

Here are some good questions to ask before coding. Bonus points for
you if you have already thought through this!

If the integer's digit is 0, what should be output be? ie, cases such
as 10, 100.

Did you notice that the reversed integer might overflow? Assume the
input is a 32-bit integer, then the reverse of 1000000003
overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0
when the reversed integer overflows.

题意
----

反转整数的各位数字。

**示例1：** x = 123, 返回 321

**示例2：** x = -123, 返回 -321

**你考虑过以下问题么？**

在开始编码前有些好的问题需要提及。如果你已经考虑到这些问题，那么应该给
你奖励加分。

如果整数的数字是`0`，应该怎样输出？例如，`10, 100`的情况。

你注意到了整数反转可能发生溢出的问题吗？假设输入的是一个`32`位的整数，
那么`1000000003`反转后将发生溢出。你应该如何处理这种情况呢？

对于这个问题，假设你的函数在出现溢出时返回`0`。

思路
----

类似于[Palindrome Number](palindromeNumber.md)问题。特保注意整数的溢出
情况。

代码
----

```C++
class Solution {
public:
	int reverse(int x) {
		if (-9 <= x && x <= 9) {
			return x;
		}
		
		int reversedNumber = 0;
		while (x) {
			if (x > 0 && reversedNumber > (INT_MAX - x) / 10) {
				return 0;
			} else if (x < 0 && reversedNumber < (INT_MIN - x) / 10) {
				return 0;
			}
			
			reversedNumber *= 10;
			reversedNumber += x % 10;
			x /= 10;
		}
		
		return reversedNumber;
	}
};
```
