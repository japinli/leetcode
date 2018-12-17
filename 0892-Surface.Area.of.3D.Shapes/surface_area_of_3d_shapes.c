/*----------------------------------------------------------------------------
 *
 * surface_area_of_3d_shapes.c
 *   On a `N * N` grid, we place some `1 * 1 * 1` cubes.
 *
 *   Each value `v = grid[i][j]` represents a tower of `v` cubes placed
 *   on top of grid cell `(i, j)`.
 *
 *   Return the total surface area of the resulting shapes.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

#define MIN(a, b)    ((a) < (b) ? (a) : (b))

int
surfaceArea(int **grid, int gridRowSize, int *gridColSizes)
{
    int area = 0;

    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSizes[i]; j++) {
            if (grid[i][j]) {
                area += 4 * grid[i][j] + 2;

                if (i) {
                    area -= MIN(grid[i - 1][j], grid[i][j]) * 2;
                }
                if (j) {
                    area -= MIN(grid[i][j - 1], grid[i][j]) * 2;
                }
            }
        }
    }
    return area;
}
