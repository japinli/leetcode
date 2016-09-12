[191. Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)
=======================

原题
----

Write a function that takes an unsigned integer and returns the number
of `1` bits it has (also known as the [Hamming weight][]).

For example, the 32-bit integer `11` has binary representation
`00000000000000000000000000001011`, so the function should return `3`.

题意
----

编写函数找出无符号整数中 bit 位为`1`的数量（也称[汉明重量][]）。

例如，`32-bit`的整数`11`的二进制表示为
`00000000000000000000000000001011`，因此函数应该返回`3`。

思路
----

1. 按位遍历整数，统计`bit`位为`1`的个数。
2. 按相邻位进行统计。

代码
----

思路1示例代码
```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        for (int i = 0; i < 32; ++i) {
	    	if ((n >> i) & 0x01) {
				cnt++;
			}
		}
		
		return cnt;
    }
};
```

思路2示例代码
```c++
class Solution {
public:
    int hammingWeight(uint32_t n) {
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
		n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
		n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
		n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
		n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
		return n;
    }
};
```

[Hamming weight]: https://en.wikipedia.org/wiki/Hamming_weight
[汉明权]: https://zh.wikipedia.org/wiki/汉明重量
