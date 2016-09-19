[70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
=====================

原题
----

You are climbing a stair case. It takes *n* steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways
can you climb to the top?

思路
----

1. 这是典型的动态规划问题，求解*n*的问题可以转换为求解 *n-1* 与 *n-2*
   的问题。这种方式是自顶向下的解决方法，通过递归可以很容易的实现。
2. 上面自顶向下的解决方法存在过多的重复计算，会导致 *leetcode* 提交超
   时，动态规划除了自顶向下的解决方法之外，还可以通过自底向上，通过保
   存已有的记录来避免重复计算。
   
代码
----

思路1示例代码（超时）
```c++
class Solution {
public:
	int climbStairs(int n) {
		if (n == 1 || n == 2) {
			return n;
		}
		
		return climbStairs(n - 1) + climbStairs(n - 2);
	}
};
```

思路2示例代码
```c++
class Solution {
public:
	int climbStairs(int n) {
		if (n == 1 || n == 2) {
			return n;
		}
		
		int minusOne = 2, minusTwo = 1;
		int ret;
		for (int i = 3; i <= n; ++i) {
			ret = minusOne + minusTwo;
			minusTwo = minusOne;
			minusOne = ret;
		}
		
		return ret;
	}
};
```
