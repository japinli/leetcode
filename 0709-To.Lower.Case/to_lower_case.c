/*----------------------------------------------------------------------------
 *
 * to_lower_case.c
 *   Implement function `ToLowerCase()` that has a string parameter str,
 *   and returns the same string in lowercase.
 *
 *----------------------------------------------------------------------------
 */

#include <stdio.h>

char *
toLowerCase(char *str)
{
    char *p = str;

    while (*p) {
        if (*p >= 'A' && *p <= 'Z') {
            *p |= 0x60;
        }
        p++;
    }

    return str;
}
