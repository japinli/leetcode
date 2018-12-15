/*----------------------------------------------------------------------------
 *
 * projection_area_of_3d_shapes.c
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
projectionArea(int **grid, int gridRowSize, int *gridColSizes)
{
    int xyz = 0;

    for (int i = 0; i < gridRowSize; i++) {
        int m1 = 0;
        int m2 = 0;

        for (int j = 0; j < gridColSizes[i]; j++) {
            if (grid[i][j]) {
                xyz++;
            }

            if (grid[i][j] > m1) {
                m1 = grid[i][j];
            }

            if (grid[j][i] > m2) {
                m2 = grid[j][i];
            }
        }

        xyz += (m1 + m2);
    }

    return xyz;
}
