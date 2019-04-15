# 509. Fibonacci Number

The __Fibonacci numbers__, commonly denoted `F(n)` form a sequence, called the
__Fibonacci sequence__, such that each number is the sum of the two preceding
ones, starting from `0` and `1`. That is,

```
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
```

Given `N`, calculate `F(N)`.

__Example 1:__

```
Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
```

__Example 2:__

```
Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
```

__Example 3:__

```
Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
```

__Note:__

`0 <= N <= 30`.
