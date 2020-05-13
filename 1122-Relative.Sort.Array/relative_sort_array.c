/*----------------------------------------------------------------------------
 *
 * relative_sort_array.c
 *   Given two arrays `arr1` and `arr2`, the elements of `arr2` are
 *   distinct, and all elements in `arr2` are also in `arr1`.
 *
 *   Sort the elements of arr1 such that the relative ordering of items
 *   in `arr1` are the same as in `arr2`.  Elements that don't appear
 *   in `arr2` should be placed at the end of `arr1` in ascending order.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

static int
intCompare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int *
relativeSortArray(int *arr1, int arr1Size, int *arr2, int arr2Size,
                  int *returnSize)
{
    int *result = (int *) malloc(sizeof(int) * arr1Size);
    int  index = 0;

    /* sort the arr1 order by arr2 into result */
    for (int i = 0; i < arr2Size; i++) {
        int count = 0;
        for (int j = 0; j < arr1Size; j++) {
            if (arr1[j] == arr2[i]) {
                count++;
                arr1[j] = -1;
            }
        }
        while (count) {
            result[index++] = arr2[i];
            count--;
        }
    }

    /* sort the arr1 and then copy the remainder elements */
    qsort(arr1, arr1Size, sizeof(int), intCompare);
    while (index < arr1Size) {
        result[index] = arr1[index];
        index++;
    }

    *returnSize = arr1Size;
    return result;
}
