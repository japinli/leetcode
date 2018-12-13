/*----------------------------------------------------------------------------
 *
 * self_dividing_numbers.c
 *   A self-dividing number is a number that is divisible by every digit
 *   it contains.
 *
 *   For example, `128` is a self-dividing number because
 *   `128 % 1 == 0`, `128 % 2 == 0`, and `128 % 8 == 0`.
 *
 *   Also, a self-dividing number is not allowed to contain the digit
 *   zero.
 *
 *   Given a lower and upper number bound, output a list of every
 *   possible self dividing number, including the bounds if possible.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool
isSelfDividingNumber(int num)
{
    int n = num;
    int r;

    while (n) {
        r = n % 10;
        if (r == 0 || num % r != 0) {
            return false;
        }
        n /= 10;
    }

    return true;
}

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
selfDividingNumbers(int left, int right, int *returnSize)
{
    int *result = (int *) malloc(sizeof(int) * 10001);
    int size = 0;

    while (left <= right) {
        if (isSelfDividingNumber(left)) {
            result[size++] = left;
        }

        left++;
    }

    *returnSize = size;
    return result;
}
