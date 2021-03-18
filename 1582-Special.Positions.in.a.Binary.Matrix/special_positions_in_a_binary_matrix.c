/*----------------------------------------------------------------------------
 *
 * special_positions_in_a_binary_matrix.c
 *   Given a `rows x cols` matrix `mat`, where `mat[i][j]` is either `0` or
 *   `1`, return the number of special positions in `mat`.
 *
 *   A position `(i,j)` is called special if `mat[i][j] == 1` and all other
 *   elements in row `i` and column `j` are `0` (rows and columns are
 *   0-indexed).
 *----------------------------------------------------------------------------
 */
#if 0
int
numSpecial(int **mat, int matSize, int *matColSize)
{
    int count = 0;

    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1) {
                int k;
                for (k = 0; k < matSize; k++) {
                    if (mat[k][j] == 1 && k != i) {
                    	break;
                    }
                }
                if (k != matSize) {
                	continue;
                }

                for (k = 0; k < matColSize[i]; k++) {
                    if (mat[i][k] == 1 && k != j) {
                    	break;
                    }
                }
                if (k != matColSize[i]) {
                    continue;
                }
                count++;
            }
        }
    }

    return count;
}

#endif

#define MAX_LEN 101

int
numSpecial(int **mat, int matSize, int *matColSize)
{
    int rows[MAX_LEN] = {0};
    int cols[MAX_LEN] = {0};
    int count = 0;

    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1) {
                rows[i]++;
                cols[j]++;
            }
        }
    }

    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
                count++;
            }
        }
    }

    return count;
}
