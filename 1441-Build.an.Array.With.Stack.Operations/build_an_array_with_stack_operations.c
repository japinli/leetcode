/*----------------------------------------------------------------------------
 *
 * build_an_array_with_stack_operations.c
 *   Given an array `target` and an integer `n`. In each iteration, you will
 *   read a number from `list = {1,2,3..., n}`.
 *
 *   Build the target array using the following operations:
 *
 *   * Push: Read a new element from the beginning `list`, and push it in
 *     the array.
 *   * Pop: delete the last element of the array.
 *   * If the target array is already built, stop reading more elements.
 *
 *   You are guaranteed that the target array is strictly increasing, only
 *   containing numbers between 1 to `n` inclusive.
 *
 *   Return the operations to build the target array.
 *
 *   You are guaranteed that the answer is unique.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **
buildArray(int *target, int targetSize, int n, int *returnSize)
{
    int idx = 0;
    char **result = (char **) malloc(sizeof(char *) * (2 * n));

    for (int i = 0, j = 1; i < targetSize && j <= n; i++, j++) {
        if (j < target[i]) {
            while (j < target[i]) {
                result[idx++] = "Push";
                result[idx++] = "Pop";
                j++;
            }
        }

        result[idx++] = "Push";
    }

    *returnSize = idx;
    return result;
}
