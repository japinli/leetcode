# 942. DI String Match

Given a string `S` that __only__ contains "I" (increase) or "D" (decrease), let
`N = S.length`.

Return any permutation `A` of `[0, 1, ..., N]` such that for all
`i = 0, ..., N-1`:

* If `S[i] == "I"`, then `A[i] < A[i+1]`
* If `S[i] == "D"`, then `A[i] > A[i+1]`
 

__Example 1:__

```
Input: "IDID"
Output: [0,4,1,3,2]
```

__Example 2:__

```
Input: "III"
Output: [0,1,2,3]
```

__Example 3:__

```
Input: "DDI"
Output: [3,2,0,1]
```
 

__Note:__

1. `1 <= S.length <= 10000`
2. `S` only contains characters `"I"` or `"D"`.
