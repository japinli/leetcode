/*----------------------------------------------------------------------------
 *
 * search_in_rotated_sorted_array.c
 *   You are given an integer array `nums` sorted in ascending order, and an
 *   integer `target`.
 *
 *   Suppose that `nums` is rotated at some pivot unknown to you beforehand
 *   (i.e., `[0,1,2,4,5,6,7]` might become `[4,5,6,7,0,1,2]`).
 *
 *   If `target` is found in the array return its index, otherwise,
 *   return `-1`.
 *
 *----------------------------------------------------------------------------
 */

#if 0
int
search(int *nums, int numsSize, int target)
{
    for (int i = 0; i < numsSize; i++) {
        if (target == nums[i]) {
            return i;
        }
    }

    return -1;
}
#endif

int
search(int *nums, int numsSize, int target)
{
    int lo = 0;
    int hi = numsSize - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (target == nums[mid]) {
            return mid;
        }

        if (nums[mid] < nums[lo]) {
            if (target < nums[mid] || target >= nums[lo]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        } else {
            if (target > nums[mid] || target < nums[lo]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }

    return -1;
}
