/*----------------------------------------------------------------------------
 *
 * reverse_only_letters.c
 *   Given a string `S`, return the "reversed" string where all
 *   characters that are not a letter stay in the same place, and all
 *   letters reverse their positions.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

char *
reverseOnlyLetters(char *str)
{
    char *p = str;
    char *q = str + strlen(str);

    while (p < q) {
        while ((*p < 'a' || *p > 'z') && (*p < 'A' || *p > 'Z')) {
            p++;
        }
        while ((*q < 'a' || *q > 'z') && (*q < 'A' || *q > 'Z')) {
            q--;
        }

        if (p >= q) {
            break;
        }

        char t = *p;
        *p = *q;
        *q = t;
        p++, q--;
    }

    return str;
}

/*
 * Another method using stack.
 */
char *
reverseOnlyLetters2(char *str)
{
    char st[101]; /* The length of str do not exceed 100. */
    int top = -1;
    char *p = str;

    while (*p) {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
            st[++top] = *p;
        }
        p++;
    }

    p = str;
    while (*p) {
        if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
            *p = st[top--];
        }
        p++;
    }

    return str;
}
