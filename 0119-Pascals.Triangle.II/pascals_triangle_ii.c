/*----------------------------------------------------------------------------
 *
 * pascals_triangle_ii.c
 *   Given a non-negative index k where `k <= 33`, return the kth index
 *   row of the Pascal's triangle.
 *
 *   Note that the row index starts from 0.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *
getRow(int rowIndex, int *returnSize)
{
    if (rowIndex < 0) {
        rowIndex = 0;
    }

    int *triangle = (int *) malloc(sizeof(int) * (rowIndex + 1));
    *returnSize = rowIndex + 1;

    memset(triangle, 0, sizeof(int) * (rowIndex + 1));
    triangle[0] = 1;

    for (int i = 0; i <= rowIndex; i++) {
        for (int j = i; j > 0; j--) {
            triangle[j] += triangle[j - 1];
        }
    }

    return triangle;
}
