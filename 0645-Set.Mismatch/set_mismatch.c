/*----------------------------------------------------------------------------
 *
 * set_mismatch.c
 *   The set `S` originally contains numbers from `1` to `n`. But
 *   unfortunately, due to the data error, one of the numbers in the set
 *   got duplicated to another number in the set, which results in
 *   repetition of one number and loss of another number.
 *
 *   Given an array nums representing the data status of this set after
 *   the error. Your task is to firstly find the number occurs twice and
 *   then find the number that is missing. Return them in the form of an
 *   array.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

int *
findErrorNums(int *nums, int numsSize, int *returnSize)
{
    int hash[10001] = { 0 };

    for (int i = 0; i < numsSize; i++) {
        hash[nums[i]]++;
    }

    int *result = (int *) malloc(sizeof(int) * 2);

    for (int i = 1; i <= numsSize; i++) {
        if (hash[i] > 1 || hash[i] == 0) {
            result[hash[i] ? 0 : 1] = i;
        }
    }

    *returnSize = 2;
    return result;
}
