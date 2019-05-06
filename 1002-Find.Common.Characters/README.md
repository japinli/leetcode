# 1002. Find Common Characters

Given an array `A` of strings made only from lowercase letters, return a list of
all characters that show up in all strings within the list
(__including duplicates__).  For example, if a character occurs 3 times in all
strings but not 4 times, you need to include that character three times in the
final answer.

You may return the answer in any order.

__Example 1:__

```
Input: ["bella","label","roller"]
Output: ["e","l","l"]
```

__Example 2:__

```
Input: ["cool","lock","cook"]
Output: ["c","o"]
```

Note:

1. `1 <= A.length <= 100`
2. `1 <= A[i].length <= 100`
3. `A[i][j]` is a lowercase letter.
