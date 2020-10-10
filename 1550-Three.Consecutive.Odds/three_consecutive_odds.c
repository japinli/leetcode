/*----------------------------------------------------------------------------
 *
 * three_consecutive_odds.c
 *   Given an integer array `arr`, return `true` if there are three
 *   consecutive odd numbers in the array. Otherwise, return `false`.
 *
 *----------------------------------------------------------------------------
 */

bool
threeConsecutiveOdds(int *arr, int arrSize)
{
    if (arrSize < 3) {
        return false;
    }

    for (int i = 1; i < arrSize - 1; i++) {
        if ((arr[i - 1] & 0x01) && (arr[i] & 0x01) && (arr[i + 1] & 0x01)) {
            return true;
        }
    }

    return false;
}
