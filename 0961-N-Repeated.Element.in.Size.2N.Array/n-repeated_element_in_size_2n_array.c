/*----------------------------------------------------------------------------
 *
 * n-repeated_element_in_size_2n_array.c
 *   In a array `A` of size `2N`, there are `N+1` unique elements, and
 *   exactly one of these elements is repeated `N` times.
 *
 *   Return the element repeated `N` times.
 *
 *----------------------------------------------------------------------------
 */

int
repeatedNTimes1(int *A, int ASize)
{
    char M[10000] = { 0 };
    int i = 0;

    while (M[A[i]] == 0 && i < ASize) {
        M[A[i++]]++;
    }

    return A[i];
}

int
repeatedNTimes(int *A, int ASize)
{
    for (int i = 0; i < ASize - 2; i++) {
        if (A[i] == A[i + 1] || A[i] == A[i + 2]) {
            return A[i];
        }
    }

    return A[ASize - 1];
}
