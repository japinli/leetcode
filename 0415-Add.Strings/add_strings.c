/*----------------------------------------------------------------------------
 *
 * add_strings.c
 *   Given two non-negative integers `num1` and `num2` represented as
 *   string, return the sum of `num1` and `num2`.
 *
 *   Note:
 *
 *     1. The length of both `num1` and `num2` is `< 5100`.
 *     2. Both `num1` and `num2` contains only digits `0-9`.
 *     3. Both `num1` and `num2` does not contain any leading zero.
 *     4. You must not use any built-in BigInteger library or convert
 *        the inputs to integer directly.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN    6000

static void reverse(char *str, int i, int j)
{
    char t;

    while (i < j) {
        t = str[i];
        str[i] = str[j];
        str[j] = t;
        i++, j--;
    }
}

char *
addStrings(char *num1, char *num2)
{
    char *result = (char *) malloc(sizeof(char) * MAXLEN);
    size_t len1 = strlen(num1);
    size_t len2 = strlen(num2);
    int idx = 0;
    int c = 0;
    while (len1 && len2) {
        int a = num1[--len1] - '0';
        int b = num2[--len2] - '0';

        c += (a + b);
        result[idx++] = c % 10 + '0';
        c /= 10;
    }

    while (len1) {
        int a = num1[--len1] - '0';
        c += a;
        result[idx++] = c % 10 + '0';
        c /= 10;
    }
    while (len2) {
        int a = num2[--len2] - '0';
        c += a;
        result[idx++] = c % 10 + '0';
        c /= 10;
    }
    if (c) {
        result[idx++] = c % 10 + '0';
    }
    result[idx] = '\0';

    reverse(result, 0, idx - 1);
    return result;
}
