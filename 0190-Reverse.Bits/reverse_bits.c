/*----------------------------------------------------------------------------
 *
 * reverse_bits.c
 *   Reverse bits of a given 32 bits unsigned integer.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdint.h>

uint32_t
reverseBits(uint32_t n)
{
    /* Switch halves */
    n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    /* Switch byte */
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    /* Switch 4-bit */
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    /* Switch 2-bit */
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    /* Switch bit */
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);

    return n;
}

static unsigned char
reverseCharBits(unsigned char ch)
{
    unsigned char r = 0;

    for (int i = 0; i < 8; i++) {
        r |= ((ch >> i) & 0x01) << (7 - i);
    }

    return r;
}

uint32_t
reverseBits2(uint32_t n)
{
    unsigned char *byte = (unsigned char *) &n;
    unsigned char ch;

    ch = byte[0];
    byte[0] = byte[3];
    byte[3] = ch;

    ch = byte[1];
    byte[1] = byte[2];
    byte[2] = ch;

    for (uint32_t i = 0; i < sizeof(uint32_t); i++) {
        byte[i] = reverseCharBits(byte[i]);
    }

    return n;
}
