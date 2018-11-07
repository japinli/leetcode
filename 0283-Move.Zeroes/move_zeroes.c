/*----------------------------------------------------------------------------
 *
 * move_zeroes.c
 *   Given an array `nums`, write a function to move all 0's to the end
 *   of it while maintaining the relative order of the non-zero elements.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

void
moveZeroes(int *nums, int numsSize)
{
    int idx = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i]) {
            nums[idx++] = nums[i];
        }
    }

    while (idx < numsSize) {
        nums[idx++] = 0;
    }
}
