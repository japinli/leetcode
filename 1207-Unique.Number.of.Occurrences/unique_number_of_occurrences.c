/*----------------------------------------------------------------------------
 *
 * unique_number_of_occurrences.c
 *   Given an array of integers `arr`, write a function that returns
 *   true if and only if the number of occurrences of each value in the
 *   array is unique.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

static int
cmp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

bool
uniqueOccurrences(int* arr, int arrSize)
{
    int nums[2001] = { 0 };

    for (int i = 0; i < arrSize; i++) {
        nums[arr[i] + 1000]++;
    }

    qsort(nums, 2001, sizeof(int), cmp);

    for (int i = 0; i < 2000; i++) {
        if (nums[i] && nums[i] == nums[i + 1]) {
            return false;
        }
    }

    return true;
}
