/*----------------------------------------------------------------------------
 *
 * mean.of.array.after.removing.some.elements.c
 *   Given an integer array `arr`, return the mean of the remaining
 *   integers after removing the smallest `5%` and the largest `5%`
 *   of the elements.
 *
 *   Answers within `10^5` of the actual answer will be considered
 *   accepted.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

static int
cmp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

double
trimMean(int *arr, int arrSize)
{
    int sum = 0;
    qsort(arr, arrSize, sizeof(int), cmp);

    for (int i = arrSize * 0.05; i < arrSize * 0.95; i++) {
        sum += arr[i];
    }

    return (double) sum / (arrSize * 0.9);
}
