/*----------------------------------------------------------------------------
 *
 * reverse_string_ii.c
 *   Given a string and an integer k, you need to reverse the first k
 *   characters for every 2k characters counting from the start of the
 *   string. If there are less than k characters left, reverse all of
 *   them. If there are less than 2k but greater than or equal to k
 *   characters, then reverse the first k characters and left the other
 *   as original.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

static void
reversePartialString(char *s, int beg, int end)
{
    char temp;

    while (beg < end) {
        temp = s[beg];
        s[beg] = s[end];
        s[end] = temp;
        beg++, end--;
    }
}

char *
reverseStr(char *s, int k)
{
    int len = strlen(s);
    int skip = 2 * k;
    int i = 0;

    while (i + skip < len) {
        reversePartialString(s, i, i + k - 1);

        i += skip;
    }

    if (len - i <= k) {
        reversePartialString(s, i, len - 1);
    } else {
        reversePartialString(s, i, i + k - 1);
    }

    return s;
}
