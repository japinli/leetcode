/*----------------------------------------------------------------------------
 *
 * pascals_triangle.c
 *   Given a non-negative integer numRows, generate the first numRows of
 *   Pascal's triangle.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

int **
generate(int numRows, int **columnSizes)
{
    int **t = (int **) malloc(sizeof(int **) * numRows);
    *columnSizes = (int *) malloc(sizeof(int) * numRows);

    for (int i = 0; i < numRows; i++) {
        t[i] = (int *) malloc(sizeof(int) * (i + 1));
        (*columnSizes)[i] = i + 1;

        for (int j = 0; j < i + 1; j++) {
            if (j == 0 || j == i) {
                t[i][j] = 1;
            } else {
                t[i][j] = t[i - 1][j] + t[i - 1][j - 1];
            }
        }
    }

    return t;
}

int **
generate2(int numRows, int **columnSizes)
{
    int **triangle = (int **) malloc(sizeof(int **) * numRows);
    (*columnSizes) = (int *) malloc(sizeof(int) * numRows);

    for (int i = 1; i <= numRows; i++) {
        triangle[i - 1] = (int *) malloc(sizeof(int) * i);
        triangle[i - 1][0] = triangle[i - 1][i - 1] = 1;
        (*columnSizes)[i - 1] = i;

        if (i < 3) continue;
        for (int j = 1; j < i-1; j++) {
            triangle[i - 1][j] = triangle[i - 2][j - 1] + triangle[i - 2][j];
        }
    }

    return triangle;
}
