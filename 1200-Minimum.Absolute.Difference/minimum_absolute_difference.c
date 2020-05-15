/*----------------------------------------------------------------------------
 *
 * minimum_absolute_difference.c
 *   Given an array of __distinct__ integers `arr`, find all pairs of
 *   elements with the minimum absolute difference of any two elements.
 *
 *   Return a list of pairs in ascending order(with respect to pairs),
 *   each pair `[a, b]` follows
 *
 *   * `a`, `b` are from `arr`
 *   * `a < b`
 *   * `b - a` equals to the minimum absolute difference of any two
 *     elements in `arr`
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>
#include <limits.h>

#define MIN(a, b)    ((a) < (b) ? (a) : (b))

static inline int
intCompare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int **
minimumAbsDifference(int *arr, int arrSize, int *returnSize,
                     int **returnColumnSizes)
{
    int min = INT_MAX;
    int **results;

    qsort(arr, arrSize, sizeof(int), intCompare);

    for (int i = 1; i < arrSize; i++) {
        min = MIN(min, arr[i] - arr[i - 1]);
    }

    results = (int **) malloc(sizeof(int *) * (arrSize - 1));
    *returnSize = 0;
    for (int i = 1; i < arrSize; i++) {
        if (min == arr[i] - arr[i - 1]) {
            results[*returnSize] = (int *) malloc(sizeof(int) * 2);
            results[*returnSize][0] = arr[i - 1];
            results[*returnSize][1] = arr[i];
            (*returnSize)++;
        }
    }

    *returnColumnSizes = (int *) malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return results;
}
