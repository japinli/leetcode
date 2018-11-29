/*----------------------------------------------------------------------------
 *
 * backspace_string_compare.c
 *   Given two strings `S` and `T`, return if they are equal when both
 *   are typed into empty text editors. `#` means a backspace character.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

static char *
helper(char *S)
{
    int top = -1;
    char *s = S;

    while (*s) {
        if (*s != '#') {
            S[++top] = *s;
        } else if (top > -1) {
            top--;
        }
        s++;
    }

    /* Do not forget truncate the string. */
    S[++top] = '\0';

    return S;
}

bool
backspaceCompare(char *S, char *T)
{
    S = helper(S);
    T = helper(T);

    return strcmp(S, T) == 0;
}
