/*----------------------------------------------------------------------------
 *
 * contains_duplicate.c
 *   Given an array of integers, find if the array contains any
 *   duplicates.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

static int
compare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

bool
containsDuplicate(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] == nums[i]) {
            return true;
        }
    }

    return false;
}
