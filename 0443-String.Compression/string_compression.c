/*----------------------------------------------------------------------------
 *
 * string_compression.c
 *   Given an array of characters, compress it in-place.
 *
 *   The length after compression must always be smaller than or equal
 *   to the original array.
 *
 *   Every element of the array should be a __character__ (not int) of
 *   length 1.
 *
 *   After you are done __modifying the input array__ in-place, return
 *   the new length of the array.
 *
 *   Follow up:
 *     Could you solve it using only O(1) extra space?
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

static char *
int2string(int num, int *len)
{
    static char str[1001];
    int top = -1;

    while (num) {
        str[++top] = '0' + (num % 10);
        num /= 10;
    }

    if (len) {
        *len = top;
    }
    return str;
}

int
compress(char *chars, int charsSize)
{
    int idx = 0;
    int cnt = 1;

    for (int i = 1; i <= charsSize; i++) {
        if (chars[i - 1] == chars[i]) {
            cnt++;
        } else {
            chars[idx++] = chars[i - 1];

            if (cnt > 1) {
                int t = 0;
                char *s = int2string(cnt, &t);
                while (t > -1) {
                    chars[idx++] = s[t--];
                }
            }
            cnt = 1;
        }
    }

    return idx;
}
