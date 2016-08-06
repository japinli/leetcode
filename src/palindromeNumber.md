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

数字反转。

代码
----

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
