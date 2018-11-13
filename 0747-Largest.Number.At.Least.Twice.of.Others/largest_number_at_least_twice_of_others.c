/*----------------------------------------------------------------------------
 *
 * largest_number_at_least_twice_of_others.c
 *   In a given integer array nums, there is always exactly one largest
 *   element.
 *
 *   Find whether the largest element in the array is at least twice as
 *   much as every other number in the array.
 *
 *   If it is, return the index of the largest element, otherwise return
 *   -1.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
dominantIndex(int* nums, int numsSize)
{
    int max = 0;
    int second = 0;
    int idx = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) {
            second = max;
            max = nums[i];
            idx = i;
        } else if (nums[i] != max && nums[i] > second) {
            second = nums[i];
        }
    }

    if (max < 2 * second) {
        return -1;
    }

    return idx;
}

int
dominantIndex2(int* nums, int numsSize)
{
    int maxIdx = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[maxIdx]) {
            maxIdx = i;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != nums[maxIdx] && nums[i] * 2 > nums[maxIdx]) {
            return -1;
        }
    }

    return maxIdx;
}
