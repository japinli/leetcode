/*----------------------------------------------------------------------------
 *
 * find_the_distance_valud_between_two_arrays.c
 *   Given two integer arrays `arr1` and `arr2`, and the integer `d`,
 *   return the distance value between the two arrays.
 *
 *   The distance value is defined as the number of elements `arr1[i]`
 *   such that there is not any element `arr2[j]` where
 *   `|arr1[i]-arr2[j]| <= d`.
 *
 *----------------------------------------------------------------------------
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int
findTheDistanceValue(int *arr1, int arr1Size, int *arr2, int arr2Size, int d)
{
    int distance = 0;

    for (int i = 0; i < arr1Size; i++) {
        int j;
        for (j = 0; j < arr2Size; j++) {
            if (abs(arr1[i] - arr2[j]) <= d) {
                break;
            }
        }

        distance += (j == arr2Size) ? 1 : 0;
    }

    return distance;
}
