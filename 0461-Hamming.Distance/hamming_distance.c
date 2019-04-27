/*----------------------------------------------------------------------------
 *
 * hamming_distance.c
 *   The Hamming distance between two integers is the number of
 *   positions at which the corresponding bits are different.
 *
 *   Given two integers `x` and `y`, calculate the Hamming distance.
 *
 *----------------------------------------------------------------------------
 */

int
hammingDistance(int x, int y)
{
    int distance = 0;

    for (int v = x ^ y; v > 0; v >>= 1) {
        if (v & 1) {
            distance++;
        }
    }

    return distance;
}
