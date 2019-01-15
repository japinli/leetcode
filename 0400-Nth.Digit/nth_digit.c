/*----------------------------------------------------------------------------
 *
 * nth_digit.c
 *   Find the `n-th` digit of the infinite integer sequence
 *   `1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...`
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
findNthDigit(int n)
{
    long len = 1;
    long beg = 1;
    long cnt = 9;
    char tmp[100];

    while (n > cnt * len) {
        n -= cnt * len;
        len++;
        cnt *= 10;
        beg *= 10;
    }


    beg += (n - 1) / len;
    snprintf(tmp, 100, "%ld", beg);

    return tmp[(n - 1) % len] - '0';
}
