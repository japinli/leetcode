# Rotate String

We are given two strings, `A` and `B`.

A shift on `A` consists of taking string `A` and moving the leftmost character
to the rightmost position. For example, if `A = 'abcde'`, then it will be
`'bcdea'` after one shift on `A`. Return `True` if and only if `A` can become
`B` after some number of shifts on `A`.

```
Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
```

**Note:**

* `A` and `B` will have length at most `100`.

# Solution

## 暴力破解

遍历字符串 `A` 的所有位移串，并与字符串 `B` 进行比较，若相等则返回 `true` 。
否则当字符串 `A` 及其所位移串均与字符串 `B` 不等时返回 `false` 。

**注意：**

* 当字符串 `A` 与 `B` 长度不相等时，如何移动都不能使得 `A` 和`B` 相等。

我最初实现的时候对字符串 `A` 进行了位移操作，其实这是不需要的。针对位移长度
`s`，我们可以得到 `A[s] == B[0], A[s+1] == B[1], A[s+2] == B[2]` 。

``` C
bool
rotateString(char *A, char *B)
{
    size_t len1 = strlen(A);
    size_t len2 = strlen(B);
    size_t s, i;

    if (len1 != len2) {
        return false;
    }
    if (len1 == 0) {
        return true;
    }

    for (s = 0; s < len1; ++s) {
        for (i = 0; i < len1; ++i) {
            if (A[(s+i) % len1] != B[i]) {
                break;
            }
        }

        if (i == len1) {
            return true; /* Here, we found a match. */
        }
    }

    return false;
}
```
