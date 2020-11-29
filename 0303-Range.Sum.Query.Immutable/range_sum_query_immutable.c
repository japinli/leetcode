/*----------------------------------------------------------------------------
 *
 * range_sum_query_immutable.c
 *   Given an integer array `nums`, find the sum of the elements between
 *   indices `i` and `j (i <= j)`, inclusive.
 *
 *   Implement the `NumArray` class:
 *
 *   * `NumArray(int[] nums)` Initializes the object with the integer array
 *     `nums`.
 *   * `int sumRange(int i, int j)` Return the sum of the elements of the
 *      `nums` array in the range `[i, j]` inclusive (i.e.,
 *      `sum(nums[i], nums[i + 1], ... , nums[j])`).
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

typedef struct {
    int  size;
    int *prefixSum;
} NumArray;


NumArray *
numArrayCreate(int *nums, int numsSize)
{
    int       runningSum = 0;
    NumArray *numArray;

    numArray = (NumArray *)malloc(sizeof(NumArray) + (sizeof(int) * numsSize));
    numArray->size = numsSize;
    numArray->prefixSum = (int *) ((char *)numArray + sizeof(NumArray));

    for (int i = 0; i < numsSize; i++) {
        runningSum += nums[i];
        numArray->prefixSum[i] = runningSum;
    }

    return numArray;
}

int
numArraySumRange(NumArray *obj, int i, int j)
{
    if (i == 0) {
        return obj->prefixSum[j];
    }

    return obj->prefixSum[j] - obj->prefixSum[i - 1];
}

void
numArrayFree(NumArray* obj)
{
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);

 * numArrayFree(obj);
*/
