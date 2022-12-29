# 1641. Count Sorted Vowel Strings

Given an integer `n`, return the number of strings of length `n` that
consist only of vowels `(a, e, i, o, u)` and are lexicographically
sorted.

A string s is lexicographically sorted if for all valid `i, s[i]` is the
same as or comes before `s[i+1]` in the alphabet.

__Example 1:__

```
Input: n = 1
Output: 5
Explanation: The 5 sorted strings that consist of vowels only are ["a","e","i","o","u"].
```

__Example 2:__

```
Input: n = 2
Output: 15
Explanation: The 15 sorted strings that consist of vowels only are
["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"].
Note that "ea" is not a valid string since 'e' comes after 'a' in the alphabet.
```

__Example 3:__

```
Input: n = 33
Output: 66045
```

__Constraints:__

* `1 <= n <= 50`
