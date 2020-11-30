/*----------------------------------------------------------------------------
 *
 * coin_change.c
 *   You are given coins of different denominations and a total amount of
 *   money amount. Write a function to compute the fewest number of coins
 *   that you need to make up that amount. If that amount of money cannot be
 *   made up by any combination of the coins, return `-1`.
 *
 *   You may assume that you have an infinite number of each kind of coin.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int
coinChange(int *coins, int coinsSize, int amount)
{
    int  ret;
    int *memo = (int *) malloc(sizeof(int) * (amount + 1));

    memo[0] = 0;

    for (int i = 1; i <= amount; i++) {
        memo[i] = INT_MAX;
        for (int j = 0; j < coinsSize; j++) {
            if (i - coins[j] >= 0 && memo[i - coins[j]] != INT_MAX) {
                memo[i] = MIN(memo[i - coins[j]] + 1, memo[i]);
            }
        }
    }

    ret = memo[amount] == INT_MAX ? -1 : memo[amount];
    free(memo);

    return ret;
}
