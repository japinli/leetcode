# Two Sum

Given an array of integers, return *indices* of the two numbers such that
they add up to a specific target.

You may assume the each input would have *exactly* one solution, and you
may not use the same element twice.

```
Example:
Given nums = [2, 7, 11, 15], target 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

# Solution

如果数组有序，那么我们可以从数组两端向中间遍历，当两数和与目标相等时返回
此时两个数的下标即可；否则根据两数和与目标的大小关系确定该移动的位置，直
到其相遇为止。

由于数组可能是乱序的，因此我们可以通过对数组排序然后在使用上面的方法，但
这就导致数组元素的下标发生变化，因此我们需要记录元素在原始数组中的位置。
