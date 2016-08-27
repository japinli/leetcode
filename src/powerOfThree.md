[326. Power of Three](https://leetcode.com/problems/power-of/three/)

原题
----

Given an integer, write a function to determine if it is a power of
three.

**Follow up:**

Could you do it without using any loop/recursion?

题意
----

给定一个整数，编写函数计算它是否为`3`的幂。

**跟进：**

你能否不使用循环或递归实现呢？

思路
----

1. 解决这个问题使用循环或递归实现非常简单。
2. 找出`int`类型中最大的`3`的幂的`maxThreePower`数，通过该数模给定的数，
   若给定的数模`maxThreePower`等于则该数是`3`的幂，反之，则不是。

代码
----

思路1示例代码
```c++
class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0) {
			return false;
		}
		
		while (n % 3 == 0) {
			n /= 3;
		}
		
		return n == 1;
	}
};
```

```c++
class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n <= 0) {
			return false;
		}
		// 1162261467 = 2 ^ 19
		size_t maxThreePower = 1162261467;
		
		return maxThreePower % n == 0;
	}
};
```
