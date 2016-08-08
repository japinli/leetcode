[374. Guess Number Higher or Lower](https://leetcode.com/problems/guess-number-higher-or-lower/)
===================================

原题
----

we are playing the Guess Game. The game is as follows:

I pick a number from *1* to *n*. You have to guess which number I
picked.

Every time you guess wrong, I'll tell you whether the number is higher
or lower.

You can call a pre-defined API `guess(int num)` which return 3
possible results (`-1`, `1`, or `0`):

```
-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
```

**Example:**

```
n = 10, I pick 6.

Return 6.
```

题意
----

猜数游戏如下：

我选择一个 *1* 到 *n* 的数。你来猜我选的数。

每当你猜错之后，我会告诉你这个数是更大或更小。

你可以通过调用预定义的函数 `guess(int num)` 来获得判断结果，它包含以下
三个返回值：

```
-1 : 我选中的数比你猜的数小
 1 : 我选中的数比你猜的数大
 0 : 恭喜，你猜到它了！
```

**示例：**

```
n = 10， 我选择6。

返回6。
```

思路
----

1. 从`1`到`n`遍历，当相等时返回，该思路没有充分利用`guess`函数。在
   LeetCode上提交时会超时。
2. 既然`guess`函数返回的三个值告诉了我们当前猜的值与选中的值的大小关系，
   那么我们就可以通过二分查找解决该问题。
   
代码
----

思路1示例代码（超时）
```C++
/*
 * Forward declaration of guess API
 * @param num, your guess
 * @return -1 if my number is lower, 1 if my number is higher,
 *  otherwise return 0
 */
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		for (int i = 1; i <= n; i++) {
			if (guess(i) == 0) {
				return i;
			}
		}
		
		return 0;
	}
};
```

超时测试用例：
```
2126753390
1702766719
```

思路2示例代码
```C++
/*
 * Forward declaration of guess API
 * @param num, your guess
 * @return -1 if my number is lower, 1 if my number is higher,
 *  otherwise return 0
 */
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		long low = 1;
		long high = n;
		long mid;
		int result;
		
		do {
			mid = (low + high) >> 1;
			
			result = guess(mid);			
			if (result == -1) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		} while (result != 0);
		
		return mid;
	}
};
```
