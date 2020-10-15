# 1403. Minimum Subsequence in Non-Increasing Order
 
Given the array `nums`, obtain a subsequence of the array whose sum of
elements is __strictly greater__ than the sum of the non included
elements in such subsequence. 

If there are multiple solutions, return the subsequence with 
__minimum size__ and if there still exist multiple solutions, return the
subsequence with the __maximum total sum__ of all its elements. A
subsequence of an array can be obtained by erasing some (possibly zero)
elements from the array.

Note that the solution with the given constraints is guaranteed to be
__unique__. Also return the answer sorted in __non-increasing__ order.

__Example 1:__

```
Input: nums = [4,3,10,9,8]
Output: [10,9] 
Explanation: The subsequences [10,9] and [10,8] are minimal such that
the sum of their elements is strictly greater than the sum of elements
not included, however, the subsequence [10,9] has the maximum total sum
of its elements. 
```

__Example 2:__

```
Input: nums = [4,4,7,6,7]
Output: [7,7,6] 
Explanation: The subsequence [7,7] has the sum of its elements equal to
14 which is not strictly greater than the sum of elements not included
(14 = 4 + 4 + 6). Therefore, the subsequence [7,6,7] is the minimal
satisfying the conditions. Note the subsequence has to returned in
non-decreasing order.
```

__Example 3:__

```
Input: nums = [6]
Output: [6]
```

__Constraints:__

* `1 <= nums.length <= 500`
* `1 <= nums[i] <= 100`
