[372. Super Pow](https://leetcode.com/problems/super-pow/)
================

原题
----

Your task is to calculate *$ a^b $* mod 1337 where *a* is a positive
integer and *b* is an extremely large positive integer in the form of
an array.

**Example1:**

```
a = 2
b = [3]

Result: 8
```

**Example2:**

```
a = 2
b =[1,0]

Result: 1024
```

题意
----

计算*$ a ^ b $*模`1337`，其中*a*是一个正整数，*b*是以数组形式给出的极
大的正整数。

**示例1:**

```
a = 2
b = [3]

Result: 8
```

**示例2:**

```
a = 2
b =[1,0]

Result: 1024
```

思路
----

由于`a^b % k = (a % k)^b % k`，同时由于`b`非常大，因此不能单独通过先计
算`b`的值再整体计算结果。考虑`a^123456 % k = a^123450 * a^6 =
(a^12345)^10 * a^6`。因此可以通过递归的形式求解该问题。

代码
----
```C++
class Solution {
public:
	int superPow(int a, vector<int>& b) {
		if (b.empty()) {
			return 1;
		}
		
		int last = b.back();
		b.pop_back();
		
		return powerMod(superPow(a, b), 10) * powerMod(a, last) % base_;
	}
	
private:
	int powerMod(int a, int b) {
		int ret = 1;
		a %= base_;
		
		while (b--) {
			ret = (ret * a) % base_;
		}
		
		return ret;
	}
	const int base_ = 1337;
};
```
