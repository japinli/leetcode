/*----------------------------------------------------------------------------
 *
 * make_two_arrays_equal_by_reversing_sub_arrays.c
 *   Given two integer arrays of equal length `target` and `arr`.
 *
 *   In one step, you can select any __non-empty sub-array__ of `arr`
 *   and reverse it. You are allowed to make any number of steps.
 *
 *   Return _True_ if you can make `arr` equal to `target`, or _False_
 *   otherwise.
 *
 *----------------------------------------------------------------------------
 */

bool
canBeEqual(int *target, int targetSize, int *arr, int arrSize)
{
    int hash[1001] = { 0 };

    (void) arrSize;

    for (int i = 0; i < targetSize; i++) {
        hash[target[i]]++;
        hash[arr[i]]--;
    }

    for (int i = 0; i < targetSize; i++) {
        if (hash[target[i]] != 0) {
            return false;
        }
    }

    return true;
}
