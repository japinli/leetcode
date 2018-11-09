/*----------------------------------------------------------------------------
 *
 * two_sum_ii_input_array_is_sorted.c
 *   Given an array of integers that is already sorted in ascending
 *   order, find two numbers such that they add up to a specific target
 *   number.
 *
 *   The function twoSum should return indices of the two numbers such
 *   that they add up to the target, where index1 must be less than
 *   index2.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

int *
twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    int *result = NULL;
    int i = 0, j = numbersSize - 1;

    if (numbers == NULL) {
        return NULL;
    }

    while (i < j) {
        int temp = numbers[i] + numbers[j];
        if (temp == target) {
            *returnSize = 2;
            result = (int *) malloc(sizeof(int) * 2);
            result[0] = i + 1; result[1] = j + 1;
            return result;
        } else if (temp < target) {
            i++;
        } else {
            j--;
        }
    }

    *returnSize = 0;
    return result;
}
