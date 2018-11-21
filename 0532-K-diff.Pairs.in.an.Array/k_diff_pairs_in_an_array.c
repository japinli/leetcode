/*----------------------------------------------------------------------------
 *
 * k_diff_pairs_in_an_array.c
 *   Given an array of integers and an integer k, you need to find the
 *   number of unique k-diff pairs in the array. Here a k-diff pair is
 *   defined as an integer pair (i, j), where i and j are both numbers
 *   in the array and their absolute difference is k.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

static int
compare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int
findPairs(int *nums, int numsSize, int k)
{
    int pair = 0;
    int i, j;

    qsort(nums, numsSize, sizeof(int), compare);

    i = j = 0;
    while (i < numsSize && j < numsSize) {
        if (i == j || nums[i] + k > nums[j]) {
            j++;
        } else if (nums[i] + k < nums[j]) {
            i++;
        } else {
            pair++;
            i++;
            while (j < numsSize - 1 && nums[j] == nums[j + 1]) {
                j++;
            }
            j++;
        }
    }

    return pair;
}
