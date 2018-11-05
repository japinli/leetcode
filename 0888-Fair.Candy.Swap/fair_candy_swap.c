/*----------------------------------------------------------------------------
 *
 * fair_candy_swap.c
 *   Alice and Bob have candy bars of different sizes: A[i] is the size
 *   of the i-th bar of candy that Alice has, and B[j] is the size of
 *   the j-th bar of candy that Bob has.
 *
 *   Exchange one candy bar each so that after the exchange, they both
 *   have the same total amount of candy.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

int *
fairCandySwap(int *A, int ASize, int *B, int BSize, int *returnSize)
{
    int suma, sumb, diff;
    int *exchange = NULL;

    suma = sumb = 0;
    exchange = (int *) malloc(sizeof(int) * 2);

    for (int i = 0; i < ASize; i++) {
        suma += A[i];
    }
    for (int i = 0; i < BSize; i++) {
        sumb += B[i];
    }

    diff = suma - (suma + sumb) / 2;
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < BSize; j++) {
            if (A[i] - B[j] == diff) {
                exchange[0] = A[i];
                exchange[1] = B[j];
                *returnSize = 2;
                return exchange;
            }
        }
    }

    *returnSize = 0;
    return exchange;
}

int *
fairCandySwap2(int *A, int ASize, int *B, int BSize, int *returnSize)
{
    int suma, sumb, delta;
    int bucket[100001] = { 0 };
    int *exchange = NULL;

    suma = sumb = 0;
    exchange = (int *) malloc(sizeof(int) * 2);

    for (int i = 0; i < ASize; i++) {
        suma += A[i];
    }

    for (int i = 0; i < BSize; i++) {
        sumb += B[i];
        bucket[B[i]]++;
    }

    /*
     * because suma - x + y = sumb + x - y
     * so y = (sumb - suma) / 2 + x
     * let delta = (sumb - suma) / 2
     * we should find y in bucket.
     */
    delta = (sumb - suma) / 2;

    for (int i = 0; i < ASize; i++) {
        int y = delta + A[i];
        if (y >= 1 && y <= 100000 && bucket[y]) {
            exchange[0] = A[i];
            exchange[1] = y;
            *returnSize = 2;
            return exchange;
        }
    }

    *exchange = 0;
    return exchange;
}
