/*----------------------------------------------------------------------------
 *
 * decompress_run_length_encoded_list.c
 *   We are given a list nums of integers representing a list compressed
 *   with run-length encoding.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
decompressRLElist(int *nums, int numsSize, int *returnSize)
{
    int *ret = NULL;
    int  j = 0;
    int  len = 0;

    for (int i = 0; i < numsSize; i += 2) {
        len += nums[i];
    }

    ret = (int *) malloc(sizeof(int) * len);
    for (int i = 0; i < numsSize; i += 2) {
        int repeat = nums[i];
        while (repeat--) {
            ret[j++] = nums[i + 1];
        }
    }

    *returnSize = len;
    return ret;
}
