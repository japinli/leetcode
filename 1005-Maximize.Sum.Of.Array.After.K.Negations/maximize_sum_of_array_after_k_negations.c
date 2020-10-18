/*----------------------------------------------------------------------------
 *
 * maximize_sum_of_array_after_k_negations.c
 *   Given an array `A` of integers, we __must__ modify the array in the
 *   following way: we choose an `i` and replace `A[i]` with `-A[i]`, and we
 *   repeat this process `K` times in total.  (We may choose the same index
 *   `i` multiple times.)
 *
 *   Return the largest possible sum of the array after modifying it in this
 *   way.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

static int
cmp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

#if 0
int
largestSumAfterKNegations(int *A, int ASize, int K)
{
    int i;
    int sum = 0;

    qsort(A, ASize, sizeof(int), cmp);

    if (A[0] > 0) {
        A[0] = K & 0x01 ? -A[0] : A[0];
    } else if (A[0] < 0) {
        for (i = 0; i < K && A[i] < 0; i++) {
            A[i] = -A[i];
        }

        if (i != K && A[i] != 0) {
            K -= i;
            i = A[i - 1] < A[i] ? i - 1 : i;
            A[i] = K & 0x01 ? -A[i] : A[i];
        }
    }

    for (i = 0; i < ASize; i++) {
        sum += A[i];
    }

    return sum;
}
#endif

int
largestSumAfterKNegations(int *A, int ASize, int K)
{
    int sum = 0;

    qsort(A, ASize, sizeof(int), cmp);
    for (int i = 0; i < ASize; i++) {
        if (A[i] < 0) {
            A[i] = -A[i];
            K--;
        }

        if (K == 0) {
            break;
        }
    }

    qsort(A, ASize, sizeof(int), cmp);
    A[0] = K & 0x01 ? -A[0] : A[0];

    for (int i = 0; i < ASize; i++) {
        sum += A[i];
    }

    return sum;
}
