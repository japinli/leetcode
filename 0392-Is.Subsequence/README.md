# 392. Is Subsequence

Given a string `s` and a string `t`, check if `s` is subsequence of `t`.

A subsequence of a string is a new string which is formed from the
original string by deleting some (can be none) of the characters without
disturbing the relative positions of the remaining characters. (ie,
`"ace"` is a subsequence of `"abcde"` while `"aec"` is not).

__Follow up:__

If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and
you want to check one by one to see if T has its subsequence. In this
scenario, how would you change your code?

__Example 1:__

```
Input: s = "abc", t = "ahbgdc"
Output: true
```

__Example 2:__

```
Input: s = "axc", t = "ahbgdc"
Output: false
```

__Constraints:__

* `0 <= s.length <= 100`
* `0 <= t.length <= 10^4`
* Both strings consists only of lowercase characters.
