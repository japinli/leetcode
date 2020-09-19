/*----------------------------------------------------------------------------
 *
 * can_make_arithmetic_progression_from_sequence.c
 *   Given an array of numbers `arr`. A sequence of numbers is called an
 *   arithmetic progression if the difference between any two consecutive
 *   elements is the same.
 *
 *   Return `true` if the array can be rearranged to form an arithmetic
 *   progression, otherwise, return `false`.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

static int
cmp(const void *a, const void *b)
{
    return *(int *) a - *(int *)b;
}

bool
canMakeArithmeticProgression(int *arr, int arrSize)
{
    int diff;

    qsort(arr, arrSize, sizeof(int), cmp);

    diff = arr[1] - arr[0];
    for (int i = 2; i < arrSize; i++) {
        if (diff != (arr[i] - arr[i - 1])) {
            return false;
        }
    }

    return true;
}
