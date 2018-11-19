/*----------------------------------------------------------------------------
 *
 * third_maximum_number.c
 *   Given a non-empty array of integers, return the third maximum
 *   number in this array. If it does not exist, return the maximum
 *   number. The time complexity must be in O(n).
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <limits.h>

#define MAX(a, b)    ((a) > (b) ? (a) : (b))

int
thirdMax(int* nums, int numsSize)
{
    long max1, max2, max3;

    max1 = max2 = max3 = LONG_MIN;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        } else if (nums[i] < max1 && nums[i] > max2) {
            max3 = max2;
            max2 = nums[i];
        } else if (nums[i] < max2 && nums[i] > max3) {
            max3 = nums[i];
        }
    }

    if (max3 == LONG_MIN) {
        return MAX(max1, max2);
    }

    return max3;
}
