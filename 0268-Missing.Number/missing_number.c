/*----------------------------------------------------------------------------
 *
 * missing_number.c
 *   Given an array containing `n` distinct numbers taken from
 *   `0, 1, 2, ..., n`, find the one that is missing from the array.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Gauss' Formula
 */
int
missingNumber(int *nums, int numsSize)
{
    if (numsSize <= 0) {
        return 0;
    }

    unsigned long sum = 0;

    sum = (numsSize * (numsSize + 1)) >> 1;

    for (int i = 0; i < numsSize; i++) {
        sum -= nums[i];
    }

    return sum;
}

/*
 * XOR
 */
int
missingNumber2(int *nums, int numsSize)
{
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result ^= ((i + 1) ^ nums[i]);
    }

    return result;
}

/*
 * Sort
 */
static int
compare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int
missingNumber3(int *nums, int numsSize)
{
    if (numsSize <= 0) {
        return 0;
    }

    qsort(nums, numsSize, sizeof(int), compare);

    int i;
    for (i = 0; i < numsSize; i++) {
        if (i != nums[i]) {
            return i;
        }
    }

    return i;
}
