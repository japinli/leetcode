# 922. Sort Array By Parity II

Given an array `A` of non-negative integers, half of the integers in `A` are
odd, and half of the integers are even.

Sort the array so that whenever `A[i]` is odd, `i` is odd; and whenever `A[i]`
is even, `i` is even.

You may return any answer array that satisfies this condition.

__Example 1:__

```
Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
``` 

__Note:__

1. `2 <= A.length <= 20000`
2. `A.length % 2 == 0`
3. `0 <= A[i] <= 1000`
