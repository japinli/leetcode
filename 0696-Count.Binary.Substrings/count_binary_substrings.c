/*----------------------------------------------------------------------------
 *
 * count_binary_substrings.c
 *   Give a string `s`, count the number of non-empty (contiguous)
 *   substrings that have the same number of 0's and 1's, and all the
 *   0's and all the 1's in these substrings are grouped consecutively.
 *
 *   Substrings that occur multiple times are counted the number of
 *   times they occur.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

#define MIN(a, b)    ((a) < (b) ? (a) : (b))

int
countBinarySubstrings2(char *s)
{
    static int groups[50001];
    int num_group = 0;
    int count = 1;

    size_t len = strlen(s);
    for (size_t i = 1; i <= len; i++) { /* use the '\0' to push last one */
        if (s[i - 1] == s[i]) {
            count++;
        } else {
            groups[num_group++] = count;
            count = 1;
        }
    }

    int result = 0;
    for (int i = 1; i < num_group; i++) {
        result += MIN(groups[i - 1], groups[i]);
    }

    return result;
}

int
countBinarySubstrings(char *s)
{
    int res = 0;
    int pre = 0;
    int cur = 1;

    size_t len = strlen(s);
    for (size_t i = 1; i <= len; i++) {
        if (s[i - 1] == s[i]) {
            cur++;
        } else {
            res += MIN(pre, cur);
            pre = cur;
            cur = 1;
        }
    }

    return res;
}
