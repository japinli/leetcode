# 1408. String Matching in an Array

Given an array of string `words`. Return all strings in `words` which
is substring of another word in __any__ order. 

String `words[i]` is substring of `words[j]`, if can be obtained
removing some characters to left and/or right side of `words[j]`.

__Example 1:__

```
Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
```

__Example 2:__

```
Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
```

__Example 3:__

```
Input: words = ["blue","green","bu"]
Output: []
```

__Constraints:__

* `1 <= words.length <= 100`
* `1 <= words[i].length <= 30`
* `words[i]` contains only lowercase English letters.
* It's __guaranteed__ that `words[i]` will be unique.