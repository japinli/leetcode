[390. Elimination Game](https://leetcode.com/contest/2/problems/elimination-game/)
========================

原题
----

There is a list of sorted integers from 1 to *n*. Starting from left
to right, remove the first number and every other number afterward
until you reach the end of the list.

Repeat the previous step again, but this time from right to left,
remove the right most number and every other number from the remaining
numbers.

We keep repeating the steps again, alternating left to right and right
to left, until a single number remains.

Find the last number that remains starting with a list of length *n*.

**Example:**

```
Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6
```

题意
----

有一个`1`到`n`的已序整数链表。从左到右，移除奇数位置上的元素（从左到右
编号并由1开始计数）。

重复上述步骤，但这次是从右到左，移除奇数位置上的元素（从右到左编号并由
1开始计数）。

重复上述步骤，直到只有一个元素留下为止，找到这个元素。

**示例：**

```
输入:
n = 9,
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9 编号
2 4 6 8
4 3 2 1 编号
2 6
1 2 编号
6

输出:
6
```

思路
----

1. 最初想到的办法就是通过链表遍历，并移除相应位置上的元素。此方法思路简单，易于实现。该方法需要使用额外的空间，时间复杂度为`O(n^2)`。
2. 对于长度为`n`的链表而言，在进行第一轮删除后，剩下的全为偶数。因此第一轮移除的数据个数为`n/2`或`n/2+1`。同理，第二轮移除的个数也符合上述条件。因此我们只需要经过`lg n`次就可以使得链表剩下`1`个元素。那如何找出最后剩下的元素呢？在第一轮时，从左到右无论元素个数是奇数还是偶数，剩下的元素都是以`2`开头的（特例`n=1`除外）。在第二轮删除时，从右到左元素`2`可能被保留（当此轮元素个数为偶数时）也可能被删除（当此轮元素个数为奇数时），当被删除时需要确定下一个元素。第三轮时，从左到右第一个元素肯定会被删除。按上述步骤，直到只剩一个元素位置。整理一下上述思路：

   1. 从左到右，第一个元素被删除；
   2. 从右到左，当此轮元素个数为奇数时，第一个元素被删除；
   3. 计算剩余元素个数。

那如何确定下一个元素呢？注意到在第一轮时，删除的元素跨度为`2`，第二轮时删除的元素跨度为`4`。以此类推，当第`n`轮时，删除的元素跨度为`2^n`。因此我们只要记录左边的第一个元素的位置，在需要删除左边的元素时，跳到下一个元素即可。例如，默认记录1，在第一轮时，由于需要删除左边的元素，则需要记录下一个元素为`1+(1 << (step - 1)) = 2`，其中`step`为当前轮数。

代码
----

思路1示例代码
```c++
class Solution {
public:
    int lastRemaining(int n) {
        list<int> s, t;
	for (int i = 1; i <= n; ++i) {
	    s.push_back(i);
	}
	
	while (s.size() > 1) {
	    list<int>::iterator it = s.begin();
	    for (; it != s.end() && ++it != s.end(); ++it) {
	        t.push_back(*it);
	    }
	    s = t;
	    t.clear();
	    s.reverse();
	}
	return s.front();
    }
};
```

思路2示例代码
```c++
class Solution {
public:
    int lastRemaining(int n) {
        int base = 1;
	int step = 0;
	int remain = n & 0x01 ? n - 1 : n;
	
	while (remain > 1) {
	    step++;
	    if ((step & 0x01) || (!(step & 0x01) && (remain & 0x01))) {
	        base += 1 << (step - 1);  /* find the new left element */
	    } 
	    remain >>= 1;
	}
	
	return base;
    }
};
```