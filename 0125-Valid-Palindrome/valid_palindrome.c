/*----------------------------------------------------------------------------
 *
 * valid_palindrome.c
 *   Given a string, determine if it is a palindrome, considering only
 *   alphanumeric characters and ignoring cases.
 *
 * NOTE:
 *   For the purpose of this problem, we define empty string as valid
 *   palindrome.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * Remove invalid characters in str, and return the length of valid
 * characters.
 */
static int
removeInvalidChar(char *str)
{
    char *p = str;
    char *q = str;

    while (*p) {
        if (*p >= 'A' && *p <= 'Z') {
            *q++ = *p++ | 0x60;
        } else if ((*p >= 'a' && *p <= 'z') ||
                   (*p >= '0' && *p <= '9')) {
            *q++ = *p++;
        } else {
            p++;
        }
    }

    *p = '\0';
    return q - str;
}

bool
isPalindrome(char *str)
{
    int len = removeInvalidChar(str);
    int i = 0;
    int j = len - 1;

    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }
        i++, j--;
    }

    return true;
}

bool
isPalindrome2(char *s)
{
    int len = strlen(s);
    char *p = s;
    char *q = s + len - 1;

    while (p < q) {
        if (!isalnum(*p)) {
            p++; continue;
        }
        if (!isalnum(*q)) {
            q--; continue;
        }

        if (tolower(*p++) != tolower(*q--)) {
            return false;
        }
    }

    return true;
}
