/*----------------------------------------------------------------------------
 *
 * number_complement.c
 *   Given a positive integer, output its complement number. The
 *   complement strategy is to flip the bits of its binary
 *   representation.
 *
 *   Note:
 *     1. The given integer is guaranteed to fit within the range of a
 *        32-bit signed integer.
 *     2. You could assume no leading zero bit in the integer’s binary
 *        representation.
 *----------------------------------------------------------------------------
 */

#include <stdio.h>

int
findComplement1(int num)
{
    int h = 0;
    int mask = num;
    for (int i = 0; i < 31; i++) {
        if (mask & 1) {
            h = i;
        }
        mask >>= 1;
    }

    h++;
    mask = 0;
    while (h--) {
        mask = (mask << 1) | 1;
    }

    return ~num & mask;
}

int
findComplement(int num)
{
    for (long i = 1; i <= num; i <<= 1) {
        num ^= i;
    }
    return num;
}
