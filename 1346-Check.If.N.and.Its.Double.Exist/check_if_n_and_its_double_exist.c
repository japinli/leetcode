/*----------------------------------------------------------------------------
 *
 * check_if_n_and_its_double_exist.c
 *   Given an array of integers, check if there exists two integers N
 *   and M such that N is the double of M (i.e. N = 2 * M).
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>
#include <stdbool.h>

#ifdef SOLUTION_1

bool
checkIfExist(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize; j++) {
            if (i != j && arr[i] * 2 == arr[j]) {
                return true;
            }
        }
    }

    return false;
}

#endif

#define MAX_SIZE    4001
#define BASE_NUM    2000

bool
checkIfExist(int *arr, int arrSize)
{
    /*
     * NB: We DO NOT free the memory, because it will make the runtime slower.
     */
    bool *ht = (bool *) calloc(MAX_SIZE, sizeof(bool));

    for (int i = 0; i < arrSize; i++) {
        int j = arr[i] * 2 + BASE_NUM;
        if (ht[j]) {
            return true;
        }

        if (arr[i] % 2 == 0) {
            j = arr[i] / 2 + BASE_NUM;
            if (ht[j]) {
                return true;
            }
        }

        j = arr[i] + BASE_NUM;
        ht[j] = true;
    }

    return false;
}
