/*----------------------------------------------------------------------------
 *
 * sort_array_by_increasing_frequency.c
 *   Given an array of integers `nums`, sort the array in increasing order
 *   based on the frequency of the values. If multiple values have the same
 *   frequency, sort them in decreasing order.
 *
 *   Return the sorted array.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

int *
frequencySort(int *nums, int numsSize, int *returnSize)
{
    int    hash[202] = { 0 };
    int    maxFrequency = 0;
    int   *ret = (int *) malloc(sizeof(int) * numsSize);

    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int idx = nums[i] + 100;

        if (maxFrequency < ++hash[idx]) {
            maxFrequency = hash[idx];
        }
    }

    for (int freq = 1; freq <= maxFrequency; freq++) {
        for (int i = 201; i >= 0; i--) {
            if (hash[i] == freq) {
                while (hash[i]) {
                    ret[(*returnSize)++] = i - 100;
                    hash[i]--;
                }
            }
        }
    }

    return ret;
}
