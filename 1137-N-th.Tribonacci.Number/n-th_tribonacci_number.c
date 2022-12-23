/*----------------------------------------------------------------------------
 *
 * n-th_tribonacci_number.c
 *   The Tribonacci sequence Tn is defined as follows:
 *   T_0 = 0, T_1 = 1, T_2 = 1, and T_{n+3} = T_{n} + T_{n+1} + T_{n+2}
 *   for n >= 0.
 *   Given n, return the value of T_n.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
f(int *T, int n)
{
    if (T[n] != -1) {
        return T[n];
    } else if (n < 2) {
        T[n] = n;
        return T[n];
    } else if (n == 2) {
        T[n] = 1;
        return T[n];
    }

    T[n] = f(T, n - 1) + f(T, n - 2) + f(T, n - 3);
    return T[n];
}

int
tribonacci(int n)
{
    int dp[38];
    for (int i = 0; i < 38; i++) {
        dp[i] = -1;
    }

    return f(dp, n);
}

int
tribonacci1(int n)
{
    if (n < 2) {
        return n;
    } else if (n == 2) {
        return 1;
    }

    int t0 = 0;
    int t1 = 1;
    int t2 = 1;

    for (int i = 3; i <= n; i++) {
        int t = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = t;
    }

    return t2;
}
