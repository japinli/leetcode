/*----------------------------------------------------------------------------
 *
 * sort_array_by_parity_ii.c
 *   Given an array `A` of non-negative integers, half of the integers
 *   in `A` are odd, and half of the integers are even.
 *
 *   Sort the array so that whenever `A[i]` is odd, `i` is odd; and
 *   whenever `A[i]` is even, `i` is even.
 *
 *   You may return any answer array that satisfies this condition.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>


/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
sortArrayByParityII(int *A, int ASize, int *returnSize)
{
    int *result = (int *) malloc(sizeof(int) * ASize);
    int ei = 0;    /* even index */
    int oi = 1;    /* odd index */

    for (int i = 0; i < ASize; i++) {
        if (A[i] & 0x01) {
            result[oi] = A[i];
            oi += 2;
        } else {
            result[ei] = A[i];
            ei += 2;
        }
    }

    *returnSize = ASize;
    return result;
}
