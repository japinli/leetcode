/*----------------------------------------------------------------------------
 *
 * next_greater_element_i.c
 *   You are given two arrays __(without duplicates)__ `nums1` and
 *   `nums2` where `nums1`’s elements are subset of `nums2`. Find all
 *   the next greater numbers for `nums1`'s elements in the
 *   corresponding places of `nums2`.
 *
 *   The Next Greater Number of a number `x` in `nums1` is the first
 *   greater number to its right in `nums2`. If it does not exist,
 *   output -1 for this number.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

static int
findNextGreater(int *nums, int beg, int end, int find)
{
    while (beg < end) {
        if (nums[beg] > find) {
            return nums[beg];
        }
        beg++;
    }

    return -1;
}

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
nextGreaterElement1(int *findNums, int findNumsSize,
                    int *nums, int numsSize, int *returnSize)
{
    int *result;

    result = (int *) malloc(sizeof(int) * findNumsSize);
    *returnSize = findNumsSize;

    for (int i = 0; i < findNumsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (findNums[i] == nums[j]) {
                result[i] = findNextGreater(nums, j + 1, numsSize, nums[j]);
            }
        }
    }

    return result;
}

static int
findPosition(int *nums, int numsSize, int val)
{
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            return i;
        }
    }

    return numsSize;
}

int *
nextGreaterElement(int *findNums, int findNumsSize,
                   int *nums, int numsSize, int *returnSize)
{
    int *result;

    result = (int *) malloc(sizeof(int) * findNumsSize);
    *returnSize = findNumsSize;

    for (int i = 0; i < findNumsSize; i++) {
        int pos = findPosition(nums, numsSize, findNums[i]);

        int ans = -1;
        for (int j = pos; j < numsSize; j++) {
            if (nums[j] > findNums[i]) {
                ans = nums[j];
                break;
            }
        }

        result[i] = ans;
    }

    return result;
}
