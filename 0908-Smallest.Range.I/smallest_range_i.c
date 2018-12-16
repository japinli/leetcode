/*----------------------------------------------------------------------------
 *
 * smallest_range_i.c
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
smallestRangeI(int *A, int ASize, int K)
{
    if (ASize <= 1) {
        return 0;
    }

    int max = A[0];
    int min = A[0];

    for (int i = 1; i < ASize; i++) {
        if (A[i] > max) {
            max = A[i];
        }

        if (A[i] < min) {
            min = A[i];
        }
    }

    return max - min <= 2 * K ? 0 : max - min - 2 * K;
}
