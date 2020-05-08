/*----------------------------------------------------------------------------
 *
 * count_negative_numbers_in_a_sorted_matrix.c
 *   Given a `m * n` matrix `grid` which is sorted in non-increasing
 *   order both row-wise and column-wise.
 *
 *   Return the number of negative numbers in `grid`.
 *
 *----------------------------------------------------------------------------
 */

#ifdef SOLUTION_1
int
countNegatives(int **grid, int gridSize, int *gridColSize)
{
    int count = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] < 0) {
                count += gridColSize[i] - j;
                break;
            }
        }
    }

    return count;
}
#endif

static int
binaryCount(int *array, int len)
{
    int m;
    int l = 0;
    int h = len - 1;

    while (l < h) {
        m = (l + h) / 2;
        if (array[m] >= 0) {
            l = m + 1;
        } else {
            h = m;
        }
    }

    return (array[l] >= 0) ? 0 : len - l;
}

int
countNegatives(int **grid, int gridSize, int *gridColSize)
{
    int count = 0;

    for (int i = 0; i < gridSize; i++) {
        count += binaryCount(grid[i], gridColSize[i]);
    }

    return count;
}
