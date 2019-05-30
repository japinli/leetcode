/*----------------------------------------------------------------------------
 *
 * house_robber.c
 *   You are a professional robber planning to rob houses along a
 *   street. Each house has a certain amount of money stashed, the only
 *   constraint stopping you from robbing each of them is that adjacent
 *   houses have security system connected and __it will automatically
 *   contact the police if two adjacent houses were broken into on the
 *   same night__.
 *
 *   Given a list of non-negative integers representing the amount of
 *   money of each house, determine the maximum amount of money you can
 *   rob tonight __without alerting the police__.
 *
 *----------------------------------------------------------------------------
 */

#define MAX(a, b)     ((a) > (b) ? (a) : (b))

int
rob(int *nums, int numsSize)
{
    int sum1 = 0;
    int sum2 = 0;

    if (numsSize <= 0) {
        return 0;
    } else if (numsSize == 1) {
        return nums[0];
    }

    for (int i = 0; i < numsSize; i++) {
        if (i & 0x01) {
            sum1 = MAX(sum1 + nums[i], sum2);
        } else {
            sum2 = MAX(sum1, sum2 + nums[i]);
        }
    }

    return MAX(sum1, sum2);
}
