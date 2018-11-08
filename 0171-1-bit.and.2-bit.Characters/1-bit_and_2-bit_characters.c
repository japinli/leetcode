/*----------------------------------------------------------------------------
 *
 * 1-bit_and_2-bit_characters.c
 *   We have two special characters. The first character can be
 *   represented by one bit `0`. The second character can be represented
 *   by two bits (`10` or `11`).
 *
 *   Now given a string represented by several bits. Return whether the
 *   last character must be a one-bit character or not. The given string
 *   will always end with a zero.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdbool.h>

bool
isOneBitCharacter(int *bits, int bitsSize)
{
    bool onebit;
    int i = 0;

    while (i < bitsSize) {
        if (bits[i]) {
            onebit = false;
            i += 2;
        } else {
            onebit = true;
            i++;
        }
    }

    return onebit;
}
