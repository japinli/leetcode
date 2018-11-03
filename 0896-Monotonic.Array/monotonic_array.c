/*----------------------------------------------------------------------------
 *
 * monotonic_array.c
 *   Return true if and only if the given array A is monotonic.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdbool.h>

static bool
isMonotonicInc(int *A, int ASize)
{
    for (int i = 0; i < ASize - 1; i++) {
        if (A[i] > A[i + 1]) {
            return false;
        }
    }

    return true;
}

static bool
isMonotonicDec(int *A, int ASize)
{
    for (int i = 0; i < ASize - 1; i++) {
        if (A[i] < A[i + 1]) {
            return false;
        }
    }

    return true;
}

bool
isMonotonic(int *A, int ASize)
{
    return isMonotonicDec(A, ASize) || isMonotonicInc(A, ASize);
}

/*
 * One pass.
 */
bool
isMonotonic2(int *A, int ASize)
{
    bool increasing = true;
    bool decreasing = true;

    for (int i = 0; i < ASize - 1; i++) {
        if (A[i] > A[i + 1]) {
            increasing = false;
        }
        if (A[i] < A[i + 1]) {
            decreasing = false;
        }
    }
    return increasing || decreasing;
}
