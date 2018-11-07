/*----------------------------------------------------------------------------
 *
 * remove_duplicates_from_sorted_array.c
 *   Given a sorted array `nums`, remove the duplicates in-place such
 *   that each element appear only once and return the new length.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
removeDuplicates(int *nums, int numsSize)
{
    if (numsSize < 2) {
        return numsSize;
    }

    int idx = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[idx] != nums[i]) {
            nums[++idx] = nums[i];
        }
    }

    /* Make sure that we use index, not the count of non-duplicate numbers. */
    return idx + 1;
}
