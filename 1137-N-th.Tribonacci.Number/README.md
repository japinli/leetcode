# 1137. N-th Tribonacci Number

The Tribonacci sequence Tn is defined as follows: 

$T_0 = 0$, $T_1 = 1$, $T_2 = 1$, and $T_{n+3} = T_n + T_{n+1} + T_{n+2}$ for $n >= 0$.

Given $n$, return the value of $T_n$.

__Example 1:__

```
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
```

__Example 2:__

```
Input: n = 25
Output: 1389537
```

__Constraints:__

* `0 <= n <= 37`
* The answer is guaranteed to fit within a 32-bit integer, ie. answer `<= 2^31 - 1`.



