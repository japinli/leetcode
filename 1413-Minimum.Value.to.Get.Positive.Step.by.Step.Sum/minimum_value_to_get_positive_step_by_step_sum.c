/*----------------------------------------------------------------------------
 *
 * minimum_value_to_get_positive_step_by_step_sum.c
 *   Given an array of integers `nums`, you start with an initial
 *   positive value startValue.
 *
 *   In each iteration, you calculate the step by step sum of startValue
 *   plus elements in nums (from left to right).
 *
 *   Return the minimum positive value of startValue such that the step
 *   by step sum is never less than 1.
 *
 *----------------------------------------------------------------------------
 */

int
minStartValue(int *nums, int numsSize)
{
    int result = 1;
    int tmp;
    int i;

    while (1) {
        tmp = result;
        for (i = 0; i < numsSize; i++) {
            tmp += nums[i];
            if (tmp <= 0) {
                break;
            }
        }

        if (i == numsSize) {
            break;
        }
        result++;
    }

    return result;
}
