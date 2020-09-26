/*----------------------------------------------------------------------------
 *
 * groups_of_special_equivalent_strings.c
 *   You are given an array `A` of strings.
 *
 *   A move onto `S` consists of swapping any two even indexed characters of
 *   `S`, or any two odd indexed characters of `S`.
 *
 *   Two strings `S` and `T` are special-equivalent if after any number of
 *   moves onto `S`, `S` == `T`.
 *
 *   For example, `S = "zzxy"` and `T = "xyzz"` are special-equivalent
 *   because we may make the moves `"zzxy" -> "xzzy" -> "xyzz"` that swap
 *   `S[0]` and `S[2]`, then `S[1]` and `S[3]`.
 *
 *   Now, a group of special-equivalent strings from `A` is a non-empty
 *   subset of `A` such that:
 *
 *   1. Every pair of strings in the group are special equivalent, and;
 *   2. The group is the largest size possible (ie., there isn't a string
 *      `S` not in the group such that `S` is special equivalent to every
 *      string in the group)
 *
 *   Return the number of groups of special-equivalent strings from `A`.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>
#include <string.h>

/*
 * ses_t represent special-equivalent strings.
 */
typedef struct {
    int count[52];
} ses_t;


int
cmp(const void *a, const void *b)
{
    ses_t a1 = *(ses_t *) a;
    ses_t b1 = *(ses_t *) b;

    for (int i = 0; i < 52; i++) {
        if (a1.count[i] != b1.count[i]) {
            return a1.count[i] - b1.count[i];
        }
    }

    return 0;
}

int
numSpecialEquivGroups(char **A, int ASize)
{
    ses_t *aux = (ses_t *) malloc(sizeof(ses_t) * ASize);
    size_t len;
    int count = 1;

    if (ASize <= 1) {
        return ASize;
    }

    memset(aux, 0, sizeof(ses_t) * ASize);
    len = strlen(A[0]);
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < len; j++) {
            aux[i].count[A[i][j] - 'a' + j % 2 * 26]++;
        }
    }

    qsort(aux, ASize, sizeof(ses_t), cmp);

    for (int i = 1; i < ASize; i++) {
        if (cmp(&(aux[i-1]), &(aux[i])) != 0) {
            count++;
        }
    }

    return count;
}
