/*----------------------------------------------------------------------------
 *
 * toeplitz_matrix.c
 *   Given an `M x N` matrix, return `True` if and only if the matrix is
 *   _Toeplitz_.
 *
 * See: https://en.wikipedia.org/wiki/Toeplitz_matrix
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdbool.h>

/*
 * Toeplitz matrix is every diagonal from top-left to bottom-right has
 * the same element. i.e. a[i][j] = a[i+1][j+1].
 */
bool
isToeplitzMatrix(int **matrix, int matrixRowSize, int *matrixColSizes)
{
    for (int i = 0; i < matrixRowSize - 1; i++) {
        for (int j = 0; j < matrixColSizes[0] - 1; j++) {
            if (matrix[i][j] != matrix[i + 1][j + 1]) {
                return false;
            }
        }
    }

    return true;
}

bool
isToeplitzMatrix2(int **matrix, int matrixRowSize, int *matrixColSizes)
{
    int idx;
    int groups[41];

    for (int i = 0; i < 41; i++) {
        groups[i] = -1;
    }

    for (int i = 0; i < matrixRowSize; i++) {
        for (int j = 0; j < matrixColSizes[0]; j++) {
            idx = (i - j) + 20;
            if (groups[idx] == -1) {
                groups[idx] = matrix[i][j];
            } else if (groups[idx] != matrix[i][j]) {
                return false;
            }
        }
    }

    return true;
}
