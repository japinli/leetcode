/*----------------------------------------------------------------------------
 *
 * sum_of_even_numbers_after_queries.c
 *   We have an array `A` of integers, and an array `queries` of
 *   queries.
 *
 *   For the `i`-th query `val = queries[i][0]`,
 *   `index = queries[i][1]`, we add `val` to `A[index]`. Then, the
 *   answer to the `i`-th query is the sum of the even values of `A`.
 *
 *   _(Here, the given `index = queries[i][1]` is a 0-based index, and
 *   each query permanently modifies the array A.)_
 *
 *   Return the answer to all queries.  Your `answer` array should have
 *   `answer[i]` as the answer to the `i`-th query.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

int *
sumEvenAfterQueries(int *A, int ASize, int **queries, int queriesSize,
                    int *queriesColSize, int *returnSize)
{
    int sum = 0;
    int *result = (int *) malloc(sizeof(int) * queriesSize);
    *returnSize = queriesSize;
    for (int i = 0; i < ASize; i++) {
        if ((A[i] & 0x01) == 0) {
            sum += A[i];
        }
    }

    for (int i = 0; i < queriesSize; i++) {
        int val = queries[i][0];
        int idx = queries[i][1];

        if ((A[idx] & 0x01) && (val & 0x01)) {
            sum += A[idx] + val;
        } else if (!(A[idx] & 0x01) && !(val & 0x01)) {
            sum += val;
        } else if (!(A[idx] & 0x01) && (val & 0x01)) {
            sum -= A[idx];
        }

        result[i] = sum;
        A[idx] += val;

    }

    return result;
}
