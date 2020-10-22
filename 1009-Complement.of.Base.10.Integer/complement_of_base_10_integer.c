/*----------------------------------------------------------------------------
 *
 * complement_of_base_10_integer.c
 *   Every non-negative integer `N` has a binary representation.  For example,
 *   `5` can be represented as `"101"` in binary, `11` as `"1011"` in binary,
 *   and so on.  Note that except for `N = 0`, there are no leading zeroes in
 *   any binary representation.
 *
 *   The complement of a binary representation is the number in binary you
 *   get when changing every `1` to a `0` and `0` to a `1`.  For example,
 *   the complement of `"101"` in binary is `"010"` in binary.
 *
 *   For a given number `N` in base-10, return the complement of it's binary
 *   representation as a base-10 integer.
 *
 *----------------------------------------------------------------------------
 */

#if 0
int
bitwiseComplement(int N)
{
    int res = 0;
    int i = 0;

    if (!N) {
        return 1;
    }

    while (N) {
        if (!(N & 0x01)) {
            res |= (1 << i);
        }
        i++;
        N >>= 1;
    }

    return res;
}
#endif

int
bitwiseComplement(int N)
{
    int i = 0;
    int t = N;

    if (!N) {
        return 1;
    }

    while (N) {
        i++;
        N >>= 1;
    }

    return (1 << i) - t - 1;
}
