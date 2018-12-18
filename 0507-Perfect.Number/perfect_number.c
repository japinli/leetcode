/*----------------------------------------------------------------------------
 *
 * perfect_number.c
 *   We define the Perfect Number is a positive integer that is equal to
 *   the sum of all its positive divisors except itself.
 *
 *   Now, given an integer n, write a function that returns true when it
 *   is a perfect number and false when it is not.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdbool.h>

bool
checkPerfectNumber(int num)
{
    if (num <= 1) {
        return false;
    }

    int sum = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += (i + num / i);
        }
    }

    return sum == num;
}

static int
pn(int p)
{
    return (1 << (p - 1)) * ((1 << p) - 1);
}

bool
checkPerfectNumber2(int num)
{
    static int primes[] = {2, 3, 5, 7, 13, 17, 19, 31};
    size_t len = sizeof(primes) / sizeof(int);

    for (size_t i = 0; i < len; i++) {
        if (pn(primes[i]) == num) {
            return true;
        }
    }

    return false;
}
