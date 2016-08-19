[367. Valid Perfect Square](https://leetcode.com/problems/valid-perfect-square/)
===========================

原题
----

Given a positive integer *num*, write a function which returns True if
*num* is a perfect square else False.

**Note: Do note** use any built-in library function such as `sqrt`.

**Example 1:**

```
Input: 16
Returns: True
```

**Example 2:**

```
Input: 14
Returns: False
```

题意
----

给定一个正数*num*,判断它是否是完全平方数，若是返回True，否则返回False。

**注意：不要**使用任何内建的函数，例如`sqrt`。

**示例1：**

```
输入: 16
返回: True
```

**示例2：**

```
输入: 14
返回: False
```

思路
----

1. 最易想到的办法就是通过设置一个计数器，计算平方并与给定的数判断是否
   相等，在计算平方时需要避免溢出。
2. 利用二分查找的思想，首先选`[1, num]`区间的中位数进行判断，若大于
   `num`，则在区间`[1, (1+num)/2 - 1]`执行查找，否则在区间
   `[(1+num)/2 + 1, num]`执行查找。
3. 注意到完全平方数有如下性质：

   ```
   1^2 = 1
   2^2 = 1 + 3
   3^2 = 1 + 3 + 5
   4^2 = 1 + 3 + 5 + 7
   ...
   n^2 = n + n(n-1)
   ```
   
   因此，我们可以通过从`1`开始将所有的奇数相加，若出现与`num`相等的元
   素则该数就是一个完全平方数。

代码
----

思路1示例代码
```c++
class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num < 1) {
			return false;
		}
		
		long long square = 1;
		for (int i = 2; square < num; ++i) {
			square = i * i;
		}
		
		return square == num;
	}
};
```

超时测试用例：
```
输入： 21474836647
```

思路2示例代码
```c++
class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num <= 1) {
			return num == 1 ? true : false;
		}
		
		long low = 1;
		long high = num / 2;
		
		while (low <= high) {
			long mid = (low + high) / 2;
			long square = mid * mid;
			if (square == num) {
				return true;
			} else if (square > num) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		
		return false;
	}
};
```

思路3示例代码

下面代码中为了避免由于相加可能出现的溢出情况，采用了存储空间更大的`long`类型。
```
class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num < 1) {
			return false;
		}

		long square = 0;
		for (long i = 1; square < num; i += 2) {
			square += i;
		}
		
		return square == num;
	}
};
```
我们可以通过下面的方法避免由于相加导致的溢出。
```
class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num < 1) {
			return false;
		}
		
		for (int i = 1; num > 0; i += 2) {
			num -= i;
		}
		
		return num == 0 ? true : false;
	}
};
```
