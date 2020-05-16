# 1394. Find Lucky Integer in an Array

Given an array of integers `arr`, a lucky integer is an integer which has a
frequency in the array equal to its value.

Return a _lucky integer_ in the array. If there are multiple lucky integers
return the __largest__ of them. If there is no lucky integer return __-1__.

__Example 1:__

```
Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
```

__Example 2:__

```
Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
```

__Example 3:__

```
Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.
```

__Example 4:__

```
Input: arr = [5]
Output: -1
```

__Example 5:__

```
Input: arr = [7,7,7,7,7,7,7]
Output: 7
```

__Constraints:__

* `1 <= arr.length <= 500`
* `1 <= arr[i] <= 500`
