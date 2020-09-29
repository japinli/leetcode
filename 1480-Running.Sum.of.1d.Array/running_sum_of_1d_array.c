/*----------------------------------------------------------------------------
 *
 * running_sum_of_1d_array.c
 *   Given an array `nums`. We define a running sum of an array as
 *   `runningSum[i] = sum(nums[0]...nums[i])`.
 *
 *   Return the running sum of `nums`.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

int *
runningSum(int *nums, int numsSize, int *returnSize)
{
    int *res = (int *) malloc(sizeof(int) * numsSize);

    res[0] = nums[0];

    for (int i = 1; i < numsSize; i++) {
        res[i] = res[i - 1] + nums[i];
    }

    *returnSize = numsSize;
    return res;
}

#if 0
int *
runningSum(int *nums, int numsSize, int *returnSize)
{
    for (int i = 1; i < numsSize; i++) {
        nums[i] += nums[i - 1];
    }

    *returnSize = numsSize;
    return nums;
}
#endif
