/*----------------------------------------------------------------------------
 *
 * 3sum.c
 *   Given an array nums of `n` integers, are there elements `a, b, c` in
 *   nums such that `a + b + c = 0`? Find all unique triplets in the array
 *   which gives the sum of zero.
 *
 *   Notice that the solution set must not contain duplicate triplets.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

static int
cmp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int **
threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int cap = 4;
    int **res = (int **) calloc(cap, sizeof(int *));
    int *columnSizes = (int *) calloc(cap, sizeof(int));
    int count = 0;
    int i, j, k;

    qsort(nums, numsSize, sizeof(int), cmp);

    for (i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i - 1] == nums[i]) {
            continue;
        }

        j = i + 1;
        k = numsSize - 1;
        while (j < k) {
            int s = nums[i] + nums[j] + nums[k];

            if (s > 0) {
                k--;
            } else if (s < 0) {
                j++;
            } else {
                if (count == cap) {
                    cap *= 2;
                    res = (int **) realloc(res, sizeof(int *) * cap);
                    columnSizes = (int *) realloc(columnSizes, sizeof(int) * cap);
                }
                res[count] = (int *) malloc(sizeof(int) * 3);
                res[count][0] = nums[i];
                res[count][1] = nums[j];
                res[count][2] = nums[k];
                columnSizes[count] = 3;
                count++;
                while (j < k && nums[j] == nums[j + 1]) j++;
                while (j < k && nums[k] == nums[k - 1]) k--;
                j++, k--;
            }
        }
    }

    *returnColumnSizes = columnSizes;
    *returnSize = count;
    return res;
}
