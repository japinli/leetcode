/*----------------------------------------------------------------------------
 *
 * generate_a_string_with_characters_that_have_odd_counts.c
 *   Given an integer `n`, return a string with `n` characters such that
 *   each character in such string occurs an odd number of times.
 *
 *   The returned string must contain only lowercase English letters. If
 *   there are multiples valid strings, return any of them.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

char *
generateTheString(int n)
{
    char *res = (char *) malloc(sizeof(char) * (n + 1));

    res[n] = '\0';

    if (n && (n & 0x01) == 0) {
        res[--n] = 'b';

    }

    while (n > 0) {
        res[--n] = 'a';
    }

    return res;
}
