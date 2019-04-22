/*----------------------------------------------------------------------------
 *
 * squares_of_a_sorted_array.c
 *   Given an array of integers `A` sorted in non-decreasing order,
 *   return an array of the squares of each number, also in sorted
 *   non-decreasing order.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

int *
sortedSquares(int *A, int ASize, int *returnSize)
{
    int beg = 0;
    int end = ASize - 1;
    int idx = end;
    int *result = (int *) malloc(sizeof(int) * ASize);

    while (beg <= end) {
        if (abs(A[beg]) < abs(A[end])) {
            result[idx] = A[end] * A[end];
            end--;
        } else {
            result[idx] = A[beg] * A[beg];
            beg++;
        }
        idx--;
    }

    *returnSize = ASize;
    return result;
}
