/*----------------------------------------------------------------------------
 *
 * binary_search.c
 *   Given a __sorted__ (in ascending order) integer array nums of `n`
 *   elements and a `target` value, write a function to search `target`
 *   in `nums`. If `target` exists, then return its index, otherwise
 *   return `-1`.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
search(int *nums, int numsSize, int target)
{
    int l = 0;
    int r = numsSize - 1;

    while (l <= r) {
        int m = (l + r) / 2;
        if (target == nums[m]) {
            return m;
        } else if (target < nums[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return -1;
}
