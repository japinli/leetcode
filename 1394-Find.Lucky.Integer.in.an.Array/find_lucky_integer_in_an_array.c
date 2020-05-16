/*----------------------------------------------------------------------------
 *
 * find_lucky_integer_in_an_array.c
 *   Given an array of integers `arr`, a lucky integer is an integer
 *   which has a frequency in the array equal to its value.
 *
 *   Return a _lucky integer_ in the array. If there are multiple lucky
 *   integers return the largest of them. If there is no lucky integer
 *   return -1.
 *
 *----------------------------------------------------------------------------
 */

int
findLucky(int *arr, int arrSize)
{
    int frequency[501] = { 0 };

    for (int i = 0; i < arrSize; i++) {
        frequency[arr[i]]++;
    }

    for (int i = 500; i > 0; i--) {
        if (frequency[i] == i) {
            return i;
        }
    }

    return -1;
}
