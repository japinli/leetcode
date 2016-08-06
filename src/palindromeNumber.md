[9. Palindrome Number](https://leetcode.com/problems/palindrome-number/)
======================

原题
----

Determine whether an integer is a palindrome. Do this without extra space.

题意
----

判断一个整数是否是回文。不要使用额外的空间。

思路
----

1. 数字反转。
2. 同样利用数字反转，但是只进行部分反转即可判断，参考LeetCode上
   [gaurav5][]的方法。

代码
----

思路1示例代码
```C++
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) {        // negative number is not a palindrome
			return false;
		}
		if (x < 10) {       // a single number is a palindrome
			return true;
		}
		
		long xx = x;
		long digit = 0;    // avoid overflow
		
		while (x) {
			sum = sum * 10 + x % 10;
			x /= 10;
		}
		
		return digit == xx;
	}
};
```

思路2示例代码
```C++
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x && x % 10 == 0)) {
			return false;
		}
		
		int digit = 0;
		while (x > digit) {
			digit = digit * 10 + x % 10;
			x /= 10;
		}
		
		/*
		 * For example:
		 * 1221 ==> x(12) == digit(12)
		 * 121  ==> x(1) == digit(12) / 10
		 */
		return x == digit || x == digit / 10;
	}
};
```

[gaurav5]: https://discuss.leetcode.com/topic/12820/an-easy-c-8-lines-code-only-reversing-till-half-and-then-compare
