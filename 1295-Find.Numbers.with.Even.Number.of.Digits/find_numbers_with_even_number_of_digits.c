/*----------------------------------------------------------------------------
 *
 * find_numbers_with_even_number_of_digits.c
 *   Given an array `nums` of integers, return how many of them contain
 *   an even number of digits.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

static int
isEvenDigits(int num)
{
    if ((num < 10) || (num >= 100 && num < 1000) ||
        (num >= 10000 && num < 100000)) {
        return 0;
    }

    return 1;
}

static int
isEvenDigits2(int num)
{
    int cnt = 0;

    while (num) {
        cnt++;
        num /= 10;
    }

    return cnt % 2 == 0;
}

int
findNumbers(int *nums, int numsSize)
{
    int even_num = 0;

    for (int i = 0; i < numsSize; i++) {
        even_num += isEvenDigits(nums[i]);
    }

    return even_num;
}
