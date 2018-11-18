/*----------------------------------------------------------------------------
 *
 * maximum_average_subarray_i.c
 *   Given an array consisting of `n` integers, find the contiguous
 *   subarray of given length `k` that has the maximum average value.
 *   And you need to output the maximum average value.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

#define MAX(a, b)    ((a) > (b) ? (a) : (b))

double
findMaxAverage(int *nums, int numsSize, int k)
{
    for (int i = 1; i < numsSize; i++) {
        nums[i] += nums[i - 1];
    }

    double max = nums[k - 1] / (double) k;

    for (int i = k; i < numsSize; i++) {
        max = MAX(max, (nums[i] - nums[i - k]) / (double) k);
    }

    return max;
}
