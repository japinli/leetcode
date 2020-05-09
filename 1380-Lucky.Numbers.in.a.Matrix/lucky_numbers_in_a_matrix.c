/*----------------------------------------------------------------------------
 *
 * lucky_numbers_in_a_matrix.c
 *   Given a `m * n` matrix of distinct numbers, return all lucky
 *   numbers in the matrix in any order.
 *
 *   A lucky number is an element of the matrix such that it is the
 *   minimum element in its row and maximum in its column.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>
#include <limits.h>

int *
luckyNumbers(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
    int *result = (int *) malloc(sizeof(int) * 51);
    int  cnt = 0;

    for (int i = 0; i < matrixSize; i++) {
        int c;
        int min = INT_MAX;
        int max = INT_MIN;

        for (int j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
                c = j;
            }
        }

        for (int r = 0; r < matrixSize; r++) {
            if (matrix[r][c] > max) {
                max = matrix[r][c];
            }
        }

        if (max == min) {
            result[cnt++] = min;
        }
    }

    *returnSize = cnt;
    return result;
}
