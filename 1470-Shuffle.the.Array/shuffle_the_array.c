/*----------------------------------------------------------------------------
 *
 * shuffle_the_array.c
 *   Given the array `nums` consisting of `2n` elements in the form
 *   `[x1,x2,...,xn,y1,y2,...,yn]`.
 *
 *   Return the array in the form `[x1,y1,x2,y2,...,xn,yn]`.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

int *
shuffle(int *nums, int numsSize, int n, int *returnSize)
{
    int *result = (int *) malloc(sizeof(int) * numsSize);
    int idx = 0;

    for (int i = 0; i < n; i++) {
        result[idx++] = nums[i];
        result[idx++] = nums[i + n];
    }

    *returnSize = idx;

    return result;
}
