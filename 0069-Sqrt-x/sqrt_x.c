/*----------------------------------------------------------------------------
 *
 * sqrt_x.c
 *   Implement `int sqrt(int x)``.
 *
 *   Compute and return the square root of `x`, where `x` is guaranteed
 *   to be a non-negative integer.
 *
 *   Since the return type is an integer, the decimal digits are
 *   truncated and only the integer part of the result is returned.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <math.h>

int
mySqrt(int x)
{
    for (int i = 1; i <= x; i++) {
        int t = i * i;
        if (t < 0 || t > x) {
            return i - 1;
        }
    }

    return x;
}

int
mySqrt3(int x)
{
    long r = x;

    while (r * r > x) {
        r = (r + x / r) / 2;
    }

    return r;
}

int
mySqrt2(int x)
{
    return sqrt(x);
}
