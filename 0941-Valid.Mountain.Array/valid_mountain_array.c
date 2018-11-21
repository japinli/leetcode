/*----------------------------------------------------------------------------
 *
 * valid_mountain_array.c
 *   Given an array `A` of integers, return `true` if and only if it is
 *   a valid mountain array.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdbool.h>

bool
validMountainArray(int *A, int ASize)
{
    int l = 0;
    int r = ASize - 1;

    while (l < ASize - 1 && A[l] < A[l + 1]) {
        l++;
    }

    while (r > 0 && A[r - 1] > A[r]) {
        r--;
    }

    return l == r && l != 0 && r != ASize - 1;
}
