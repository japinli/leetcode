# 844. Backspace String Compare

Given two strings `S` and `T`, return if they are equal when both are typed into
empty text editors. `#` means a backspace character.

__Example 1:__

```
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".
```

__Example 2:__

```
Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".
```

__Example 3:__

```
Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".
```

__Example 4:__

```
Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
```

__Note:__

1. `1 <= S.length <= 200`
2. `1 <= T.length <= 200`
3. `S` and `T` only contain lowercase letters and '#' characters.

__Follow up:__

* Can you solve it in `O(N)` time and `O(1)` space?
