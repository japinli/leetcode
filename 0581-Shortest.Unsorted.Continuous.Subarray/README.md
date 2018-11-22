# 581. Shortest Unsorted Continuous Subarray

Given an integer array, you need to find one continuous subarray that if you
only sort this subarray in ascending order, then the whole array will be sorted
in ascending order, too.

You need to find the __shortest__ such subarray and output its length.

__Example 1:__

```
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
```
__Note:__

1. Then length of the input array is in range `[1, 10,000]`.
2. The input array may contain duplicates, so ascending order here means `<=`.
