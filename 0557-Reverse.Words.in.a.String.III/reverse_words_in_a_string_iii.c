/*----------------------------------------------------------------------------
 *
 * reverse_words_in_a_string_iii.c
 *   Given a string, you need to reverse the order of characters in each
 *   word within a sentence while still preserving whitespace and
 *   initial word order.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

static void
reverseString(char *s, int b, int e)
{
    char t;

    while (b < e) {
        t = s[b];
        s[b] = s[e];
        s[e] = t;
        b++, e--;
    }
}

char *
reverseWords(char *s)
{
    char *p = s;
    int b = 0;
    int e = 0;

    while (*p) {
        if (*p == ' ') {
            reverseString(s, b, e - 1);
            b = e + 1;
        }

         e++, p++;
    }

    if (e - b > 1) {
        reverseString(s, b, e - 1);
    }

    return s;
}

char *
reverseWords2(char *s)
{
    int len = strlen(s);
    int b = 0;

    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            reverseString(s, b, i - 1);
            b = i + 1;
        }
    }

    return s;
}
