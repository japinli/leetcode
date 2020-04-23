/*----------------------------------------------------------------------------
 *
 * create_target_array_in_the_given_oreder.c
 *
 *   Given two arrays of integers `nums` and `index`. Your task is to create
 *   target array under the following rules:
 *
 *   * Initially target array is empty.
 *   * From left to right read `nums[i]` and `index[i]`, insert at index
 *     `index[i]` the value `nums[i]` in target array.
 *   * Repeat the previous step until there are no elements to read in `nums`
 *     and `index`.
 *
 * Return the target array.
 * It is guaranteed that the insertion operations will be valid.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>


int *
createTargetArray(int *nums, int numsSize, int *index, int indexSize,
                  int *returnSize)
{
    int  cnt = 0;
    int *target = (int *) malloc(sizeof(int) * indexSize);
    *returnSize = indexSize;

    for (int i = 0; i < indexSize; i++) {
        if (index[i] + 1 > cnt) {
            target[index[i]] = nums[i];
        } else {
            for (int j = cnt; j > index[i]; j--) {
                target[j] = target[j - 1];
            }
            target[index[i]] = nums[i];
        }
        cnt++;
    }

    return target;
}
