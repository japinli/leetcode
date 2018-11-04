/*----------------------------------------------------------------------------
 *
 * max_consecutive_ones.c
 *   Given a binary array, find the maximum number of consecutive 1s in
 *   this array.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
findMaxConsecutiveOnes(int *nums, int numsSize)
{
    int max = 0, cur = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i]) {
            cur++;
        } else {
            max = max > cur ? max : cur;
            cur = 0;
        }
    }

    return max > cur ? max : cur;
}

int
findMaxConsecutiveOnes2(int *nums, int numsSize)
{
    int max = 0, cur = 0;

    for (int i = 0; i < numsSize; i++) {
        cur = (nums[i] == 0 ? 0 : cur + 1);
        max = max > cur ? max : cur;
    }

    return max;
}
