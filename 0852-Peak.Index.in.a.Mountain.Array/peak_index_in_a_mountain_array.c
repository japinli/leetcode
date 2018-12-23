/*----------------------------------------------------------------------------
 *
 * peak_index_in_a_mountain_array.c
 *   Let's call an array A a mountain if the following properties hold:
 *
 *     * `A.length >= 3`
 *     * There exists some `0 < i < A.length - 1` such that
 *       `A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]`
 *
 *   Given an array that is definitely a mountain, return any `i` such
 *   that `A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]`.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
peakIndexInMountainArray(int *A, int ASize)
{
    int i = 0;
    int j = ASize - 1;

    while (i <= j) {
        int m = i + (j - i) / 2;

        if (A[m - 1] < A[m] && A[m] > A[m + 1]) {
            return m;
        } else if (A[m - 1] < A[m] && A[m] < A[m + 1]) {
            i = m + 1;
        } else {
            j = m - 1;
        }
    }

    return -1;
}
