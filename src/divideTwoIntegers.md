[29. Divide Two Integers](https://leetcode.com/problems/divide-two-integers/)
=========================

原题
----

Divide two integers without using multiplication, division and mod
operator.

If it is overflow, return MAX_INT.

题意
----

不使用乘法、除法和模运算计算两个数的相处。

如果出现溢出返回`MAX_INT`。

思路
----

1. 除法运算可以利用减法元算替代，因此采用多次相减解决此问题。该思路虽
   然正确可行，但是运行时间较长，在LeetCode上提交会超时。
2. 由于一个数左移`1`位代表乘以`2`，因此可以利用这个特性解决该问题。该
   方法在取绝对值时需要注意溢出问题。

代码
----

思路1示例代码（超时）
```C++
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0 || (divisor == -1 && dividend == INT_MIN)) {
			return INT_MAX;
		}
		
		if (dividend == 0) {
			return 0;
		} else if (divisor == 1 || divisor == -1) {
			return divisor == 1 ? dividend : -dividend;
		}
		
		int sign = (dividend < 0) ^ (divisor < 0);
		
		long a = labs(dividend);
		long b = labs(divisor);
		
		int cnt = 0;
		while (a >= b) {
			a -= b;
			cnt++;
		}
		
		return sign ? -cnt : cnt;
	}
};
```

思路2示例代码
```C++
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0 || (divisor == -1 && dividend == INT_MIN)) {
			return INT_MAX;
		}
		
		int sign = (dividend < 0) ^ (divisor < 0);
	    long divid = labs(dividend);
		long divis = labs(divisor);
		
		if (divid == 0) {
			return 0;
		} else if (divis == 1) {
			return sign ? -divid : divid;
		}
		
		int cnt = 0;		
		while (divid >= divis) {
			long tmp = divis, mul = 1;
			while (divid >= (tmp << 1)) {
				mul <<= 1;
				tmp <<= 1;
			}
	
			cnt += mul;
			divid -= tmp;
		}

		return sign ? -cnt : cnt;
	}
};
```
