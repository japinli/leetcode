/*----------------------------------------------------------------------------
 *
 * replace_elements_with_greatest_element_on_right_side.c
 *   Given an array `arr`, replace every element in that array with the
 *   greatest element among the elements to its right, and replace the
 *   last element with `-1`.
 *
 *   After doing so, return the array.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

int *
replaceElements(int *arr, int arrSize, int *returnSize)
{
    int  rmax = -1;
    int *ret = (int *) malloc(sizeof(int) * arrSize);
    *returnSize = arrSize;

    for (int i = arrSize - 1; i >= 0; i--) {
        ret[i] = rmax;
        if (rmax < arr[i]) {
            rmax = arr[i];
        }
    }

    return ret;
}
