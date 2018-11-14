/*----------------------------------------------------------------------------
 *
 * find_pivot_index.c
 *   Given an array of integers nums, write a method that returns the
 *   "pivot" index of this array.
 *
 *   We define the pivot index as the index where the sum of the numbers
 *   to the left of the index is equal to the sum of the numbers to the
 *   right of the index.
 *
 *   If no such index exists, we should return -1. If there are multiple
 *   pivot indexes, you should return the left-most pivot index.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

int
pivotIndex1(int *nums, int numsSize)
{
    int *sums = (int *) malloc(sizeof(int) * (numsSize + 1));
    int pivot = -1;

    sums[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        sums[i + 1] = nums[i] + sums[i];
    }

    for (int i = 0; i < numsSize; i++) {
        if (sums[i] == sums[numsSize] - sums[i] - nums[i]) {
            pivot = i;
            break;
        }
    }

    free(sums);

    return pivot;
}

int
pivotIndex(int *nums, int numsSize)
{
    int pivot = -1;
    int sum = 0;
    int halfSum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    for (int i = 0; i < numsSize; i++) {
        int temp = sum - nums[i];

        if (temp % 2 == 0 && temp >> 1 == halfSum) {
            pivot = i;
            break;
        }

        halfSum += nums[i];
    }

    return pivot;
}
