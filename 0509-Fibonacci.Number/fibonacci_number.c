/*----------------------------------------------------------------------------
 *
 * fibonacci_number.c
 *   The __Fibonacci numbers__, commonly denoted `F(n)` form a sequence,
 *   called the __Fibonacci sequence__, such that each number is the sum
 *   of the two preceding ones, starting from `0` and `1`. That is,
 *
 *   ```
 *   F(0) = 0,   F(1) = 1
 *   F(N) = F(N - 1) + F(N - 2), for N > 1.
 *   ```
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
fib(int N)
{
    int a = 0;
    int b = 1;

    while (N--) {
        int t = a + b;
        a = b;
        b = t;
    }

    return a;
}
