# 62. Unique Paths

A robot is located at the top-left corner of a `m x n` grid (marked
'Start' in the diagram below).

The robot can only move either down or right at any point in time. The
robot is trying to reach the bottom-right corner of the grid (marked
'Finish' in the diagram below).

How many possible unique paths are there?

__Example 1:__

```
Input: m = 3, n = 7
Output: 28
```

__Example 2:__

```
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```

__Example 3:__

```
Input: m = 7, n = 3
Output: 28
```

__Example 4:__

```
Input: m = 3, n = 3
Output: 6
```

__Constraints:__

* `1 <= m, n <= 100`
* It's guaranteed that the answer will be less than or equal to `2 * 10^9`.
