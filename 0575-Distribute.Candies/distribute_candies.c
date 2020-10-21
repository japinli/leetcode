/*----------------------------------------------------------------------------
 *
 * distribute_candies.c
 *   You have `n` candies, the i-th candy is of type `candies[i]`.
 *
 *   You want to distribute the candies equally between a sister and a
 *   brother so that each of them gets `n / 2` candies (`n` is even). The
 *   sister loves to collect different types of candies, so you want to give
 *   her the maximum number of different types of candies.
 *
 *   Return the maximum number of different types of candies you can give to
 *   the sister.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

#if 0
static int
cmp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int
distributeCandies(int *candies, int candiesSize)
{
    int count = 1;

    qsort(candies, candiesSize, sizeof(int), cmp);

    for (int i = 1; i < candiesSize && count < candiesSize / 2; i++) {
        if (candies[i - 1] != candies[i]) {
            count++;
        }
    }

    return count;
}
#endif

int
distributeCandies(int *candies, int candiesSize)
{
    int  count = 0;
    char map[200001] = { 0 };

    for (int i = 0; i < candiesSize; i++) {
        if (map[candies[i] + 100000] == 0) {
            map[candies[i] + 100000] = 1;
            count++;
        }

        if (count == candiesSize / 2) {
            break;
        }
    }

    return count;
}
