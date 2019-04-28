/*----------------------------------------------------------------------------
 *
 * matrix_cells_in_distance_order.c
 *   We are given a matrix with `R` rows and `C` columns has cells with
 *   integer coordinates `(r, c)`, where `0 <= r < R` and `0 <= c < C`.
 *
 *   Additionally, we are given a cell in that matrix with coordinates
 *   `(r0, c0)`.
 *
 *   Return the coordinates of all cells in the matrix, sorted by their
 *   distance from `(r0, c0)` from smallest distance to largest
 *   distance.  Here, the distance between two cells `(r1, c1)` and
 *   `(r2, c2)` is the Manhattan distance, `|r1 - r2| + |c1 - c2|`. (You
 *   may return the answer in any order that satisfies this condition.)
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

struct manhattan_distance
{
    int len;
    int row;
    int col;
};

static inline int
get_manhattan_distance(int r1, int c1, int r2, int c2)
{
    int r = r1 - r2;
    int c = c1 - c2;

    return (r < 0 ? -r : r) + (c < 0 ? -c : c);
}

static int
compare_manhattan_distance(const void *a, const void *b)
{
    struct manhattan_distance *p = (struct manhattan_distance *) a;
    struct manhattan_distance *q = (struct manhattan_distance *) b;

    return p->len - q->len;
}

int **
allCellsDistOrder(int R, int C, int r0, int c0,
                  int *returnSize, int **returnColumnSizes)
{
    int idx = 0;
    int sz = R * C;
    int **results = NULL;
    struct manhattan_distance distances[sz];

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            distances[idx].row = i;
            distances[idx].col = j;
            distances[idx].len = get_manhattan_distance(i, j, r0, c0);
            idx++;
        }
    }

    qsort(distances, sz, sizeof(struct manhattan_distance),
          compare_manhattan_distance);

    results = (int **) malloc(sizeof(int *) * sz);
    (*returnColumnSizes) = (int *) malloc(sizeof(int) * sz);
    for (int i = 0; i < sz; i++) {
        (*returnColumnSizes)[i] = 2;
        results[i] = (int *) malloc(sizeof(int) * 2);
        results[i][0] = distances[i].row;
        results[i][1] = distances[i].col;
    }

    *returnSize = sz;
    return results;
}
