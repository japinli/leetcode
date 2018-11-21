# 941. Valid Mountain Array

Given an array `A` of integers, return `true` if and only if it is a valid
mountain array.

Recall that `A` is a mountain array if and only if:

* `A.length >= 3`
* There exists some `i` with `0 < i < A.length - 1` such that:
  - `A[0] < A[1] < ... A[i-1] < A[i]`
  - `A[i] > A[i+1] > ... > A[B.length - 1]`

__Example 1:__

```
Input: [2,1]
Output: false
```

__Example 2:__

```
Input: [3,5,5]
Output: false
```

__Example 3:__

```
Input: [0,3,2,1]
Output: true
```

__Note:__

1. `0 <= A.length <= 10000`
2. `0 <= A[i] <= 10000`
