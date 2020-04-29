/*----------------------------------------------------------------------------
 *
 * cells_with_odd_values_in_a_matrix.c
 *   Given `n` and `m` which are the dimensions of a matrix initialized
 *   by zeros and given an array `indices` where `indices[i] = [ri, ci]`.
 *   For each pair of `[ri, ci]` you have to increment all cells in row
 *   `ri` and column `ci` by `1`.
 *
 *   Return the _number of cells with odd values_ in the matrix after
 *   applying the increment to all `indices`.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
oddCells(int n, int m, int **indices, int indicesSize, int *indicesColSize)
{
    int A[51][51] = { 0 };
    int count = 0;

    (void) indicesColSize;

    for (int i = 0; i < indicesSize; i++) {
        int r = indices[i][0];
        int c = indices[i][1];

        for (int j = 0; j < n; j++) {
            A[j][c]++;
        }

        for (int j = 0; j < m; j++) {
            A[r][j]++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] % 2 == 1) {
                count++;
            }
        }
    }

    return count;
}
