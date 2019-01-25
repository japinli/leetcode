/*----------------------------------------------------------------------------
 *
 * find_first_and_last_position_of_element_in_sorted_array.c
 *   Given an array of integers `nums` sorted in ascending order, find
 *   the starting and ending position of a given `target` value.
 *
 *   Your algorithm's runtime complexity must be in the order of
 *   `O(log n)`.
 *
 *   If the `target` is not found in the array, return `[-1, -1]`.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

int *
searchRange(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = (int *) malloc(sizeof(int) * 2);
    int l = 0;
    int r = numsSize - 1;

    *returnSize = 2;
    result[0] = result[1] = -1;

    while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) {
            result[0] = result[1] = m;
            break;
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    if (result[0] == -1) {
        return result;
    }

    l = result[0];
    while (l > 0 && nums[--l] == target) {
        result[0] = l;
    }

    r = result[1];
    while (r < numsSize - 1 && nums[++r] == target) {
        result[1] = r;
    }

    return result;
}
