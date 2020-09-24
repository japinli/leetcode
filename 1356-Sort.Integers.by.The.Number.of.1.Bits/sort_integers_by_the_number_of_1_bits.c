/*----------------------------------------------------------------------------
 *
 * sort_integers_by_the_number_of_1_bits.c
 *   Given an integer array `arr`. You have to sort the integers in the
 *   array in ascending order by the number of 1's in their binary
 *   representation and in case of two or more integers have the same
 *   number of 1's you have to sort them in ascending order.
 *
 *   Return the sorted array.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

static int
countBits(int a)
{
    int cnt = 0;
    while (a > 0) {
        cnt++;
        a &= a - 1;
    }

    return cnt;
}

static int
cmp(const void *a, const void *b)
{
    int a1 = *(int *) a;
    int b1 = *(int *) b;
    int bit1 = countBits(a1);
    int bit2 = countBits(b1);

    return bit1 - bit2 == 0 ? a1 - b1 : bit1 - bit2;
}

int *
sortByBits(int *arr, int arrSize, int *returnSize)
{
    qsort(arr, arrSize, sizeof(int), cmp);

    *returnSize = arrSize;
    return arr;
}
