/*----------------------------------------------------------------------------
 *
 * find_all_numbers_disappered_in_an_array.c
 *   Given an array of integers where 1 <= a[i] <= n (n = size of array),
 *   some elements appear twice and others appear once.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *
findDisappearedNumbers(int *nums, int numsSize, int *returnSize)
{
    int *disappered = NULL;

    disappered = (int *) malloc(sizeof(int) * (numsSize + 1));
    memset(disappered, 0, sizeof(int) * (numsSize + 1));

    for (int i = 0; i < numsSize; i++) {
        disappered[nums[i]]++;
    }

    int idx = 0;
    for (int i = 1; i < numsSize + 1; i++) {
        if (!disappered[i]) {
            disappered[idx++] = i;
        }
    }

    (*returnSize) = idx;
    return disappered;
}
