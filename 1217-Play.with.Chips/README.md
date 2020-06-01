# 1217. Play with Chips

There are some chips, and the i-th chip is at position `chips[i]`.

You can perform any of the two following types of moves __any number of times__
(possibly zero) __on any chip__:

* Move the `i`-th chip by 2 units to the left or to the right with a cost of __0__.
* Move the `i`-th chip by 1 unit to the left or to the right with a cost of __1__.

There can be two or more chips at the same position initially.

Return the minimum cost needed to move all the chips to the same position (any position).

__Example 1:__

```
Input: chips = [1,2,3]
Output: 1
Explanation: Second chip will be moved to positon 3 with cost 1. First chip will be moved to position 3 with cost 0. Total cost is 1.
```

__Example 2:__

```
Input: chips = [2,2,2,3,3]
Output: 2
Explanation: Both fourth and fifth chip will be moved to position two with cost 1. Total minimum cost will be 2.
```

__Constraints:__

* `1 <= chips.length <= 100`
* `1 <= chips[i] <= 10^9`
