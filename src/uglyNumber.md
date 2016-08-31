[263. Ugly Number](https://leetcode.com/problems/ugly-number/)
==================

原题
----

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include `2,
3, 5`. For example, `6, 8` are ugly while `14` is not ugly since it
includes another prime factor `7`.

Note that `1` is typically treated as an ugly number.

题意
----

编写一个函数判断给定的数是否为*ugly number*。

*Ugly number*是素因子只包含`2, 3, 5`的数。例如`6, 8`是*ugly number*，
而`14`不是，因为`14`包含`7`这个素数因子。

注意通常我们将`1`视为*ugly number*。

思路
----

辗转相除。


代码
----

```c++
class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0) {
			return false;
		}
		if (num == 1) {
			return true;
		}
		
		while (!(num % 2)) { num >>= 1; }
		while (!(num % 3)) { num /= 3; }
		while (!(num % 5)) { num /= 5; }
		
		return num == 1;
	}
};
```

```c++
class Solution {
public:
	bool isUgly(int num) {
		if (num <= 0) {
			return false;
		}
		
		for (int i = 6; i > 1 && num; i--) {
			while (num % i == 0) { num /= i; }
		}
		return num == 1;
	}
};
```
