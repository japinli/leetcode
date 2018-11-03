/*----------------------------------------------------------------------------
 *
 * reshape_the_matrix.c
 *
 *   You're given a matrix represented by a two-dimensional array, and
 *   two positive integers r and c representing the row number and
 *   column number of the wanted reshaped matrix, respectively.
 *
 *   The reshaped matrix need to be filled with all the elements of the
 *   original matrix in the same row-traversing order as they were.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

int**
matrixReshape(int **nums, int numsRowSize, int numsColSize,
              int r, int c, int **columnSizes, int *returnSize)
{

    if (numsRowSize * numsColSize != r * c) {
        r = numsRowSize;
        c = numsColSize;
    }

    int **matrix = (int **) malloc(sizeof(int *) * r);
    (*columnSizes) = (int *) malloc(sizeof(int) * r);
    for (int i = 0; i < r; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * c);
        (*columnSizes)[i] = c;
    }

    int k = 0, l = 0;
    for (int i = 0; i < numsRowSize; i++) {
        for (int j = 0; j < numsColSize; j++) {
            if (l == c) {
                /* new row */
                k++;
                l = 0;
            }
            matrix[k][l++] = nums[i][j];
        }
    }

    *returnSize = r;
    return matrix;
}

/*
 * Based on the 2-D matrix how stored in memory.
 */
int**
matrixReshape2(int **nums, int numsRowSize, int numsColSize,
               int r, int c, int **columnSizes, int *returnSize)
{

    if (numsRowSize * numsColSize != r * c) {
        r = numsRowSize;
        c = numsColSize;
    }

    int **matrix = (int **) malloc(sizeof(int *) * r);
    (*columnSizes) = (int *) malloc(sizeof(int) * r);
    for (int i = 0; i < r; i++) {
        matrix[i] = (int *) malloc(sizeof(int) * c);
        (*columnSizes)[i] = c;
    }

    int count = 0;
    for (int i = 0; i < numsRowSize; i++) {
        for (int j = 0; j < numsColSize; j++) {
            matrix[count / c][count % c] = nums[i][j];
            count++;
        }
    }

    *returnSize = r;
    return matrix;
}
