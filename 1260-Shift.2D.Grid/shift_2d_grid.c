/*----------------------------------------------------------------------------
 *
 * shift_2d_grid.c
 *   Given a 2D `grid` of size `m x n` and an integer `k`. You need to shift
 *   the grid `k` times.
 *
 *   In one shift operation:
 *
 *   * Element at `grid[i][j]` moves to `grid[i][j + 1]`.
 *   * Element at `grid[i][n - 1]` moves to `grid[i + 1][0]`.
 *   * Element at `grid[m - 1][n - 1]` moves to `grid[0][0]`.
 *
 *   Return the 2D grid after applying shift operation `k` times.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>
#include <string.h>

int **
shiftGrid(int **grid, int gridSize, int *gridColSize, int k, int *returnSize,
          int **returnColumnSizes)
{
    int  len = gridSize * gridColSize[0];
    int *t = (int *) malloc(sizeof(int) * len);
    int idx = 0;
    int tmp[103] = { 0 };

    k %= len;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            t[idx++] = grid[i][j];
        }
    }

    memcpy(tmp, t + len - k, sizeof(int) * k);
    memmove(t + k, t, sizeof(int) * (len - k));
    memcpy(t, tmp, sizeof(int) * k);

    idx = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            grid[i][j] = t[idx++];
        }
    }

    free(t);
    *returnSize = gridSize;
    *returnColumnSizes = gridColSize;
    return grid;
}
