/*----------------------------------------------------------------------------
 *
 * array_partition_i.c
 *   Given an array of 2n integers, your task is to group these integers
 *   into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn)
 *   which makes sum of min(ai, bi) for all i from 1 to n as large as
 *   possible.
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
arrayPairSum(int *nums, int numssz)
{
    int sum = 0;

    qsort(nums, numssz, sizeof(int), compare);

    for (int i = 0; i < numssz; i += 2) {
        sum += nums[i];
    }

    return sum;
}


int
arrayPairSum2(int *nums, int numssz)
{
    int bucket[20001] = { 0 };

    for (int i = 0; i < numssz; i++) {
        bucket[nums[i] + 10000]++;
    }

    int sum = 0;
    int flag = 1;

    for (int i = 0; i < 20001; /* void */) {
        if (bucket[i] >= 1) {
            sum = flag ? sum + i - 10000 : sum;
            flag ^= 1;
            bucket[i]--;
        }

        /* skip empty bucket */
        if (bucket[i] == 0) {
            i++;
        }
    }

    return sum;
}
