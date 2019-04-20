/*----------------------------------------------------------------------------
 *
 * remove_outermost_parentheses.c
 *   A valid parentheses string is either empty `("")`, `"(" + A + ")"`,
 *   or `A + B`, where `A` and `B` are valid parentheses strings, and
 *   `+` represents string concatenation.  For example, `""`, `"()"`,
 *   `"(())()"`, and `"(()(()))"` are all valid parentheses strings.
 *
 *   A valid parentheses string `S` is primitive if it is nonempty, and
 *   there does not exist a way to split it into `S = A+B`, with `A` and
 *   `B` nonempty valid parentheses strings.
 *
 *   Given a valid parentheses string `S`, consider its primitive
 *   decomposition: `S = P_1 + P_2 + ... + P_k`, where `P_i` are
 *   primitive valid parentheses strings.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH   10001

char *
removeOuterParentheses1(char *s)
{
    char *result;
    char stack[MAX_LENGTH];
    int  top = 0;
    int  idx = 0;
    char *p = s;

    if (s == NULL) {
        return NULL;
    }

    result = (char *) malloc(sizeof(char) * MAX_LENGTH);
    stack[top++] = *p++;

    while (*p) {
        if (*p == ')') {
            top--;
        } else {
            stack[top++] = *p;
        }

        if (top == 0) {  /* The stack is empty. */
            s++;
            while (s != p) {
                result[idx++] = *s++;
            }
            s++;
        }
        p++;
    }
    result[idx] = 0;
    return result;
}

char *
removeOuterParentheses(char *s)
{
    char    *result = NULL;
    size_t  len = strlen(s);
    size_t  num = 1;
    size_t  idx = 0;

    if (s == NULL) {
        return result;
    }

    result = (char *) malloc(sizeof(char) * len);

    for (size_t i = 1; i < len; i++) {
        if (s[i] == '(') {
            num++;
        } else {
            num--;
        }

        if (num) {
            result[idx++] = s[i];
        } else {
            num = 1;
            i++;
        }
    }
    result[idx] = 0;

    return result;
}
