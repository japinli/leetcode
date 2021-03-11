# 1716. Calculate Money in Leetcode Bank

Hercy wants to save money for his first car. He puts money in the Leetcode
bank __every day__.

He starts by putting in `$1` on Monday, the first day. Every day from Tuesday
to Sunday, he will put in `$1` more than the day before. On every subsequent
Monday, he will put in `$1` more than the __previous Monday__.

Given `n`, return _the total amount of money he will have in the Leetcode bank at the end of the `n-th` day_.

__Example 1:__

```
Input: n = 4
Output: 10
Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.
```

__Example 2:__

```
Input: n = 10
Output: 37
Explanation: After the 10th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2nd Monday, Hercy only puts in $2.
```

__Example 3:__

```
Input: n = 20
Output: 96
Explanation: After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.
```

__Constraints:__

* `1 <= n <= 1000`
