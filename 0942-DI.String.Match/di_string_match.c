/*----------------------------------------------------------------------------
 *
 * di_string_match.c
 *   Given a string `S` that __only__ contains "I" (increase) or "D"
 *   (decrease), let `N = S.length`.
 *
 *   Return any permutation `A` of `[0, 1, ..., N]` such that for all
 *   `i = 0, ..., N-1`:
 *
 *   - If `S[i] == "I"`, then `A[i] < A[i+1]`
 *   - If `S[i] == "D"`, then `A[i] > A[i+1]`
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *
diStringMatch(char *s, int *returnSize)
{
    size_t len = strlen(s);
    size_t i = 0;
    size_t l = 0;
    size_t r = len;

    int *result = (int *) malloc(sizeof(int) * (len + 1));
    while (*s) {
        if (*s++ == 'D') {
            result[i++] = r--;
        } else {
            result[i++] = l++;
        }
    }

    result[i] = l;

    *returnSize = len + 1;
    return result;
}
