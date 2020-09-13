# 1370. Increasing Decreasing String

Given a string `s`. You should re-order the string using the following
algorithm:

1. Pick the __smallest__ character from `s` and __append__ it to the result.
2. Pick the __smallest__ character from `s` which is greater than the last
   appended character to the result and __append__ it.
3. Repeat step 2 until you cannot pick more characters.
4. Pick the __largest__ character from `s` and __append__ it to the result.
5. Pick the __largest__ character from `s` which is smaller than the last
   appended character to the result and __append__ it.
6. Repeat step 5 until you cannot pick more characters.
7. Repeat the steps from 1 to 6 until you pick all characters from `s`.

In each step, if the smallest or the largest character appears more than
once you can choose any occurrence and append it to the result.

Return _the result string_ after sorting `s` with this algorithm.

__Example 1:__

```
Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
```

__Example 2:__

```
Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.
```

__Example 3:__

```
Input: s = "leetcode"
Output: "cdelotee"
```

__Example 4:__

```
Input: s = "ggggggg"
Output: "ggggggg"
```

__Example 5:__

```
Input: s = "spo"
Output: "ops"
```

__Constraints:__

* `1 <= s.length <= 500`
* `s` contains only lower-case English letters.
