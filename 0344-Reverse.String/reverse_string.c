/*----------------------------------------------------------------------------
 *
 * reverse_string.c
 *   Write a function that takes a string as input and returns the
 *   string reversed.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

char *
reverseString(char *s)
{
    char *b = s;
    char *e = s;

    while (*e) {
        e++;
    }
    e--;

    while (b < e) {
        char t = *b;
        *b = *e;
        *e = t;
        b++, e--;
    }

    return s;
}
