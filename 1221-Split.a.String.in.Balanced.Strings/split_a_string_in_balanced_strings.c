/*----------------------------------------------------------------------------
 *
 * split_a_string_in_balanced_strings.c
 *   Balanced strings are those who have equal quantity of 'L' and 'R'
 *   characters. Given a balanced string `s` split it in the maximum
 *   amount of balanced strings. Return the maximum amount of splitted
 *   balanced strings.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
balancedStringSplit(char *s)
{
    int    c = 0;
    int    l = 0;

    while (*s) {
        if (*s++ == 'L') {
            l++;
        } else {
            l--;
        }
        if (l == 0) {
            c++;
        }
    }

    return c;
}
