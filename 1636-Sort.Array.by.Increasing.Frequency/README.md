# 1636. Sort Array by Increasing Frequency

Given an array of integers `nums`, sort the array in __increasing__ order
based on the frequency of the values. If multiple values have the same
frequency, sort them in __decreasing__ order.

Return the _sorted_ array.

__Example 1:__

```
Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
```

__Example 2:__

```
Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
```

__Example 3:__

```
Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
```

__Constraints:__

* `1 <= nums.length <= 100`
* `-100 <= nums[i] <= 100`
