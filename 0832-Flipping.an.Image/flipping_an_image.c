/*----------------------------------------------------------------------------
 *
 * flipping_an_image.c
 *  Given a binary matrix A, we want to flip the image horizontally,
 *  then invert it, and return the resulting image.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * Return an array of arrays of size `*returnSize`.
 * The sizes of the arrays are returned as `*columnSizes` array.
 *
 * Note:
 *   Both returned array and `*columnSizes` array must be malloced, assume
 *   caller calls free().
 */
int **
flipAndInvertImage(int **A, int ARowSize, int *AColSizes,
                   int **columnSizes, int *returnSize)
{
    int **B = (int **) malloc(sizeof(int *) * ARowSize);
    (*columnSizes) = (int *) malloc(sizeof(int) * ARowSize);

    for (int i = 0; i < ARowSize; i++) {
        B[i] = (int *) malloc(sizeof(int) * AColSizes[i]);
        (*columnSizes)[i] = AColSizes[i];

        for (int j = 0; j < AColSizes[i]; j++) {
            B[i][AColSizes[i] - 1 - j] = !A[i][j];
        }
    }

    *returnSize = ARowSize;
    return B;
}
