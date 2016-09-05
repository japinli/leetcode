[50. Pow(x, n)](https://leetcode.com/problems/powx-n/)
===============

原题
----

Implement pow(x, n).

思路
----

1. 连续相乘。此方法在*n*值较大时会导致*leetcode*提交超时。

2. 改进的连续相乘。在上述方法的基础上，我们可以通过对其进行改进，从而
   提高运行效率。改进的思路主要依赖对*n*分解。例如： `myPow(2, 5)` 可
   以转化为 `2^2 * 2^2 * 2`。该思路与[Divide Two Integers][]相似。

代码
----

思路1示例代码（超时）
```c++
class Solution {
public:
	double myPow(double x, int n) {
		long tn = n; /* avoid overflow when using n = -n while n = -2147483648 */
		int neg = tn < 0 ? tn = -tn, 1 : 0;
		
		if (n == 0) {
			return 1.0;
		} else if (n == 1) {
			return neg ? 1 / x : x;
		}
		
		if (x >= -0.001 && x <= 0.001) {
			return 0.0;
		} else if (x == 1.0 || x == -1.0) {
			return (!(tn & 0x01) && neg) ? 1.0 : x;
		}
		
		double tmp = x;
		while (--n) {
			x *= tmp;
		}
		
		return x;
	}
};
```

思路2示例代码
```c++
class Solution {
public:
	double myPow(double x, int n) {
		long tn = n;
		int neg = tn < 0 ? tn = -tn, 1 : 0;
		
		if (n == 0) {
			return 1.0;
		} else if (n == 1) {
			return neg ? 1 / x : x;
		}
		
		if (x >= -0.001 && x <= 0.001) {
			return 0.0;
		} else if (x == 1.0 || x == -1.0) {
			return (!(tn & 0x01) && neg) ? 1.0 : x;
		}
		
		double result = 1.0;
		while (tn > 0) {
			double tmp = x;
			int i = 1;
			while (((long)1 << i) < tn) {
				tmp *= tmp;
				i++;
			}
			
			result *= tmp;
			tn -= (long)1 << (i - 1);			
		}
		
		return neg ? 1 / result : result;
	}
};
```

[Divide Two Integers]: divideTwoIntegers.md
