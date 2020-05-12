/*----------------------------------------------------------------------------
 *
 * the_k_weakest_rows_in_a_matrix.c
 *   Given a `m * n` matrix `mat` of ones (representing soldiers) and
 *   zeros (representing civilians), return the indexes of the `k`
 *   weakest rows in the matrix ordered from the weakest to the
 *   strongest.
 *
 *   A row `i` is weaker than row `j`, if the number of soldiers in row
 *   `i` is less than the number of soldiers in row `j`, or they have
 *   the same number of soldiers but `i` is less than `j`. Soldiers are
 *   always stand in the frontier of a row, that is, always ones may
 *   appear first and then zeros.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct aux_s {
    int index;
    int value;
} aux_t;

static int
auxCompare(const void *a, const void *b)
{
    aux_t *t1 = (aux_t *) a;
    aux_t *t2 = (aux_t *) b;

    return t1->value - t2->value;
}

int *
kWeakestRows(int **mat, int matSize, int *matColSize, int k, int *returnSize)
{
    int *result = (int *) malloc(sizeof(int) * matSize);
    aux_t tmp[101];

    for (int i = 0; i < matSize; i++) {
        int soldiers = 0;
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j])
                soldiers++;
            else
                break;
        }

        tmp[i].index = i;
        tmp[i].value = soldiers;
    }

    qsort(&tmp, matSize, sizeof(aux_t), auxCompare);
    for (int i = 0; i < k; i++) {
        result[i] = tmp[i].index;
    }

    *returnSize = k;
    return result;
}
