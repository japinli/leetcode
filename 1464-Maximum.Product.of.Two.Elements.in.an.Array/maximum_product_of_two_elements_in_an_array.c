/*----------------------------------------------------------------------------
 *
 * maximum_product_of_two_elements_in_an_array.c
 *   Given the array of integers `nums`, you will choose two different
 *   indices `i` and `j` of that array. Return the maximum value of
 *   `(nums[i]-1)*(nums[j]-1)`.
 *
 *----------------------------------------------------------------------------
 */

int
maxProduct(int *nums, int numsSize)
{
    if (numsSize == 2) {
        return (nums[0] - 1) * (nums[1] - 1);
    }

    for (int i = 0; i < 2; i++) {
        int idx = i;
        int tmp;
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[j] > nums[idx]) {
                idx = j;
            }
        }

        if (idx != i) {
            tmp = nums[i];
            nums[i] = nums[idx];
            nums[idx] = tmp;
        }
    }

    return (nums[0] - 1) * (nums[1] - 1);
}
