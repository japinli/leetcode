/*----------------------------------------------------------------------------
 *
 * valid_palindrome_ii.c
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static bool
isPalindrome(char *str, int s, int e)
{
    while (s < e) {
        if (str[s++] != str[e--]) {
            return false;
        }
    }

    return true;
}

bool
validPalindrome(char *str)
{
    size_t len = strlen(str);

    for (size_t i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return isPalindrome(str, i, j - 1) || isPalindrome(str, i + 1, j);
        }
    }

    return true;
}
