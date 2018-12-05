# 925. Long Pressed Name

Your friend is typing his `name` into a keyboard.  Sometimes, when typing a
character `c`, the key might get long pressed, and the character will be typed 1
or more times.

You examine the `typed` characters of the keyboard.  Return `True` if it is
possible that it was your friends name, with some characters (possibly none)
being long pressed.

__Example 1:__

```
Input: name = "alex", typed = "aaleex"
Output: true
Explanation: 'a' and 'e' in 'alex' were long pressed.
```

__Example 2:__

```
Input: name = "saeed", typed = "ssaaedd"
Output: false
Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
```

__Example 3:__

```
Input: name = "leelee", typed = "lleeelee"
Output: true
```

__Example 4:__

```
Input: name = "laiden", typed = "laiden"
Output: true
Explanation: It's not necessary to long press any character.
```

__Note:__

1. `name.length <= 1000`.
2. `typed.length <= 1000`.
3. The characters of `name` and `typed` are lowercase letters.
