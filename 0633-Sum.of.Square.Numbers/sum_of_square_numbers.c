/*----------------------------------------------------------------------------
 *
 * sum_of_square_numbers.c
 *   Given a non-negative integer `c`, your task is to decide whether
 *   there're two integers `a` and `b` such that `a^2 + b^2 = c`.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool
judgeSquareSum(int c)
{
    int t = sqrt(c);
    for (int a = 0; a <= t; a++) {
        double b = sqrt(c - a * a);
        if (b == (int) b) {
            return true;
        }
    }

    return false;
}
