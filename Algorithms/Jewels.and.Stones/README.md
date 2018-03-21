# Jewels and Stones

You're given strings `J` representing the types of stones that are jewels,
and `S` representing the stones you have. Each character in `S` is a type
of stone you have. You want to know how many of the stones you have are
also jewels.

The letters in `J` are guaranteed distinct, and all characters in `J` and
`S` are letters. Letters are case senstive, so `"a"` is considered a
different type of stone from `"A"`.

```
Example 1:
Input: J = "aA", S = "aAAbbbb"
Output: 3

Example 2:
Input: J = "z", S = "ZZ"
Output: 0
```

**Note:**

* `S` and `J` will consist of letters and have length at most 50.
* The characters in `J` are distinct.

# Solution

## 暴力破解

遍历字符串 `J` 中的每个字符，统计其在字符串 `S` 中出现的次数。
时间复杂度 `O(n*m)` ，空间复杂度 `O(1)`。

## 桶计数

遍历字符串 `S` 统计字符出现的次数，随后遍历字符串 `J` 并统计
在 `S` 中出现的字符的总和。
时间复杂度 `O(n)` 。
