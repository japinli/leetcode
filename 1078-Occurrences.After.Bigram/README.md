# 1078. Occurrences After Bigram

Given words `first` and `second`, consider occurrences in some `text` of
the form "first second third", where `second` comes immediately after
`first`, and `third` comes immediately after `second`.

For each such occurrence, add "third" to the answer, and return the answer.

__Example 1:__

```
Input: text = "alice is a good girl she is a good student", first = "a", second = "good"
Output: ["girl","student"]
```

__Example 2:__

```
Input: text = "we will we will rock you", first = "we", second = "will"
Output: ["we","rock"]
```

__Note:__

* `1 <= text.length <= 1000`
* `text` consists of space separated words, where each word consists of
  lowercase English letters.
* `1 <= first.length, second.length <= 10`
* `first` and `second` consist of lowercase English letters.
