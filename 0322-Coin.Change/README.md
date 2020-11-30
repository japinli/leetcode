# 322. Coin Change

You are given coins of different denominations and a total amount of
money amount. Write a function to compute the fewest number of coins
that you need to make up that amount. If that amount of money cannot be
made up by any combination of the coins, return `-1`.

You may assume that you have an infinite number of each kind of coin.

__Example 1:__

```
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
```

__Example 2:__

```
Input: coins = [2], amount = 3
Output: -1
```

__Example 3:__

```
Input: coins = [1], amount = 0
Output: 0
```

__Example 4:__

```
Input: coins = [1], amount = 1
Output: 1
```

__Example 5:__

```
Input: coins = [1], amount = 2
Output: 2
```

__Constraints:__

* `1 <= coins.length <= 12`
* `1 <= coins[i] <= 2^31 - 1`
* `0 <= amount <= 10^4`
