/*----------------------------------------------------------------------------
 *
 * non_decreasing_array.c
 *   Given an array with `n` integers, your task is to check if it could
 *   become non-decreasing by modifying at most `1` element.
 *
 *   We define an array is non-decreasing if `array[i] <= array[i + 1]`
 *   holds for every `i (1 <= i < n)`.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

bool
checkPossibility(int *nums, int numsSize)
{
    int p = -1;

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            if (p != -1) {
                return false;
            }
            p = i;
        }
    }

    return p == -1 || p == 0 || p == numsSize - 2 ||
        nums[p -1] <= nums[p+1] || nums[p] <= nums[p+2];
}
