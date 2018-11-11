/*----------------------------------------------------------------------------
 *
 * maximum_product_of_three_numbers.c
 *   Given an integer array, find three numbers whose product is maximum
 *   and output the maximum product.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int
compare(const void *a, const void * b)
{
    return *(int *) a - *(int *) b;
}

int
maximumProduct(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compare);

    int result1 = nums[0] * nums[1] * nums[numsSize - 1];
    int result2 = nums[numsSize - 1] * nums[numsSize - 2] * nums[numsSize - 3];

    return result1 > result2 ? result1 : result2;
}

int
maximumProduct2(int *nums, int numsSize)
{
    int min1, min2, max1, max2, max3;

    min1 = min2 = INT_MAX;
    max1 = max2 = max3 = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min1) {
            min2 = min1;
            min1 = nums[i];
        } else if (nums[i] < min2) {
            min2 = nums[i];
        }

        if (nums[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        } else if (nums[i] > max2) {
            max3 = max2;
            max2 = nums[i];
        } else if (nums[i] > max3) {
            max3 = nums[i];
        }
    }

    int result1 = min1 * min2 * max1;
    int result2 = max1 * max2 * max3;

    return result1 > result2 ? result1 : result2;
}
