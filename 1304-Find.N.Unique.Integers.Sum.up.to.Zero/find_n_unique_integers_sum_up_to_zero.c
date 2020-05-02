/*----------------------------------------------------------------------------
 *
 * find_n_unique_integers_sum_up_to_zero.c
 *   Given an integer n, return any array containing n unique integer
 *   such that they add up to 0.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

#ifdef SOLUTION_1

int *
sumZero(int n, int *returnSize)
{
    int *result = (int *) malloc(sizeof(int) * n);
    *returnSize = n;

    for (int i = 0, j = 0; i < n / 2; i++, j += 2) {
        result[j] = i + 1;
        result[j + 1] = -result[j];
    }

    if (n % 2) {
        result[n-1] = 0;
    }

    return result;
}

#elif SOLUTION_2

int *
sumZero(int n, int *returnSize)
{
    int  sum = 0;
    int *result = (int *) malloc(sizeof(int) * n);
    *returnSize = n;

    for (int i = 1; i < n; i++) {
        result[i] = i;
        sum += i;
    }

    result[0] = -sum;

    return result;
}

#endif

int *
sumZero(int n, int *returnSize)
{
    int  fill = 1;
    int *result = (int *) malloc(sizeof(int) * n);

    for (int i = 0; i < n && (n > 1); i++) {
        result[i] = fill;

        if (fill > 0) {
            fill = 0 - fill;
        } else {
            fill = (0 - fill) + 1;
        }
    }

    if (n % 2) {
        result[n - 1] = 0;
    }

    *returnSize = n;
    return result;
}
