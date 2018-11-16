/*----------------------------------------------------------------------------
 *
 * two_sum.c
 *   Given an array of integers, return indices of the two numbers such
 *   that they add up to a specific target.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct numidx_s
{
    int num;
    int idx;
} numidx_t;

static int
compare(const void *a, const void *b)
{
    return ((numidx_t *) a)->num - ((numidx_t *) b)->num;
}

int *
twoSum(int *nums, int numsSize, int target) {
    numidx_t *numidx = (numidx_t *) malloc(sizeof(numidx_t) * numsSize);
    int *indices = (int *) malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize; i++) {
        numidx[i].num = nums[i];
        numidx[i].idx = i;
    }

    qsort(numidx, numsSize, sizeof(numidx_t), compare);

    for (int i = 0, j = numsSize - 1; i < j; /* void */) {
        int t = numidx[i].num + numidx[j].num;
        if (t == target) {
            indices[0] = numidx[i].idx;
            indices[1] = numidx[j].idx;
            break;
        } else if (t < target) {
            i++;
        } else {
            j--;
        }
    }
    return indices;
}
