# 532. K-diff Pairs in an Array

Given an array of integers and an integer __k__, you need to find the number of
__unique__ k-diff pairs in the array. Here a __k-diff__ pair is defined as an
integer pair (i, j), where __i__ and __j__ are both numbers in the array and
their absolute difference is __k__.

__Example 1:__

```
Input: [3, 1, 4, 1, 5], k = 2
Output: 2
Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
Although we have two 1s in the input, we should only return the number of unique pairs.
```

__Example 2:__

```
Input:[1, 2, 3, 4, 5], k = 1
Output: 4
Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
```

__Example 3:__

```
Input: [1, 3, 1, 5, 4], k = 0
Output: 1
Explanation: There is one 0-diff pair in the array, (1, 1).
```

__Note:__

1. The pairs (i, j) and (j, i) count as the same pair.
2. The length of the array won't exceed 10,000.
3. All the integers in the given input belong to the range: `[-1e7, 1e7]`.
