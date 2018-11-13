/*----------------------------------------------------------------------------
 *
 * longest_continuous_increasing_subsequence.c
 *   Given an unsorted array of integers, find the length of longest
 *   continuous increasing subsequence (subarray).
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
findLengthOfLCIS(int *nums, int numsSize)
{
    if (numsSize <= 0 || nums == NULL) {
        return 0;
    }

    int max = 0;
    int s, i, t;

    for (i = 1, s = 0; i < numsSize; i++) {
        if (nums[i - 1] >= nums[i]) {
            t = i - s;
            max = max > t ? max : t;
            s = i;
        }
    }

    t = i - s;
    return max > t ? max : t;
}

int
findLengthOfLCIS2(int *nums, int numsSize)
{
    int ans = 0, s = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i - 1] >= nums[i]) {
            s = i;
        }

        ans = ans > i - s + 1 ? ans : i - s + 1;
    }

    return ans;
}
