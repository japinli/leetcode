/*----------------------------------------------------------------------------
 *
 * shortest_unsorted_continuous_subarray.c
 *   Given an integer array, you need to find one continuous subarray
 *   that if you only sort this subarray in ascending order, then the
 *   whole array will be sorted in ascending order, too.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(a, b)    ((a) > (b) ? (a) : (b))
#define MIN(a, b)    ((a) < (b) ? (a) : (b))

static int
compare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int
findUnsortedSubarray(int *nums, int numsSize)
{
    int copy[10001];

    for (int i = 0; i < numsSize; i++) {
        copy[i] = nums[i];
    }

    qsort(copy, numsSize, sizeof(int), compare);

    int beg = numsSize;
    int end = -1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != copy[i]) {
            beg = MIN(beg, i);
            end = MAX(end, i);
        }
    }

    return end - beg > 0 ? end - beg + 1 : 0;
}

int
findUnsortedSubarray2(int *nums, int numsSize)
{
    int max = INT_MIN;
    int min = INT_MAX;
    int flag = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i - 1] > nums[i]) {
            flag = 1;
        }

        if (flag) {
            min = MIN(min, nums[i]);
        }
    }

    flag = 0;
    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i + 1] < nums[i]) {
            flag = 1;
        }

        if (flag) {
            max = MAX(max, nums[i]);
        }
    }

    int l, r;
    for (l = 0; l < numsSize; l++) {
        if (min < nums[l]) {
            break;
        }
    }

    for (r = numsSize - 1; r >= 0; r--) {
        if (max > nums[r]) {
            break;
        }
    }

    return (r - l < 0) ? 0 : r - l + 1;
}
