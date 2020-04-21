/*----------------------------------------------------------------------------
 *
 * how_many_numbers_are_smaller_than_the_current_number.c
 *   Given the array nums, for each nums[i] find out how many numbers in
 *   the array are smaller than it.  That is, for each nums[i] you have
 *   to count the number of valid j's such that j != i and
 *   nums[j] < nums[i].
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>


#ifdef SOLUTION1

int *
smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize)
{
    int *ret = (int *) malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        int cnt = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] < nums[i]) {
                cnt++;
            }
        }
        ret[i] = cnt;
    }

    return ret;
}

#endif

int *
smallerNumbersThanCurrent(int * nums, int numsSize, int *returnSize)
{
    int  hash[101] = { 0 };
    int *ret = (int *) malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        hash[nums[i]]++;
    }

    for (int i = 1; i < 101; i++) {
        hash[i] += hash[i - 1];
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            ret[i] = 0;
        } else {
            ret[i] = hash[nums[i] - 1];
        }
    }

    return ret;
}
