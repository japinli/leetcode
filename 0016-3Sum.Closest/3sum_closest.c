/*----------------------------------------------------------------------------
 *
 * 3sum_closest.c
 *   Given an array `nums` of `n` integers and an integer `target`, find
 *   three integers in `nums` such that the `sum` is closest to `target`.
 *   Return the sum of the three integers. You may assume that each input
 *   would have exactly one solution.
 *
 *----------------------------------------------------------------------------
 */
#include <limits.h>
#include <stdlib.h>

static int
cmp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int
threeSumClosest(int* nums, int numsSize, int target)
{
    int diff = INT_MAX;

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 2 && diff != 0; i++) {
        int j = i + 1;
        int k = numsSize - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (abs(target - sum) < abs(diff)) {
                diff = target - sum;
            } else if (sum < target) {
                j++;
            } else {
                k--;
            }
        }
    }

    return target - diff;
}
