/*----------------------------------------------------------------------------
 *
 * check_if_n_and_its_double_exist.c
 *   Given an array of integers, check if there exists two integers N
 *   and M such that N is the double of M (i.e. N = 2 * M).
 *
 *----------------------------------------------------------------------------
 */


#ifdef SOLUTION_1

bool
checkIfExist(int* arr, int arrSize)
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
