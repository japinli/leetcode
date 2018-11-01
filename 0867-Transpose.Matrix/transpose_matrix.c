/*----------------------------------------------------------------------------
 *
 * transpose_matrix.c
 *   Given a matrix A, return the transpose of A.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size `*returnSize`.
 * The sizes of the arrays are returned as `*columnSizes` array.
 *
 * Note:
 *   Both returned array and *columnSizes array must be malloced, assume
 *   caller calls free().
 */
int**
transpose(int **A, int ARowSize, int *AColSizes,
	  int **columnSizes, int *returnSize)
{
    int **B = (int **) malloc(sizeof(int *) * AColSizes[0]);
    (*columnSizes) = (int *) malloc(sizeof(int) * AColSizes[0]);
    
    for (int i = 0; i < AColSizes[0]; i++) {
        B[i] = (int *) malloc(sizeof(int) * ARowSize);
        (*columnSizes)[i] = ARowSize;
    }
    
    for (int i = 0; i < ARowSize; i++) {        
        for (int j = 0; j < AColSizes[0]; j++) {
            B[j][i] = A[i][j];
        }
    }
    
    *returnSize = AColSizes[0];
    return B;
}
