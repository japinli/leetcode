/*----------------------------------------------------------------------------
 *
 * minimum_subsequence_in_non-increasing_order.c
 *   Given the array `nums`, obtain a subsequence of the array whose sum of
 *   elements is strictly greater than the sum of the non included elements
 *   in such subsequence.
 *
 *   If there are multiple solutions, return the subsequence with minimum
 *   size and if there still exist multiple solutions, return the subsequence
 *   with the maximum total sum of all its elements. A subsequence of an array
 *   can be obtained by erasing some (possibly zero) elements from the array.
 *
 *   Note that the solution with the given constraints is guaranteed to be
 *   unique. Also return the answer sorted in __non-increasing__ order.
 *
 *----------------------------------------------------------------------------
 */

#include <stdlib.h>

static int
cmp(const void *a, const void *b)
{
    return *(int *) b - *(int *) a;
}

int *
minSubsequence(int *nums, int numsSize, int *returnSize)
{
    int *res = (int *) malloc(sizeof(int) * numsSize);
    int sum = 0;
    int newSum = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }

    /* sort numbers in decreasing */
    qsort(nums, numsSize, sizeof(int), cmp);

    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        newSum += nums[i];
        res[*returnSize] = nums[i];
        (*returnSize)++;

        if (newSum > sum / 2) {
            break;
        }
    }

    return res;
}
