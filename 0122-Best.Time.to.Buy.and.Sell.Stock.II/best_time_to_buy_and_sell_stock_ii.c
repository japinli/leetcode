/*----------------------------------------------------------------------------
 *
 * best_time_to_buy_and_sell_stock_ii.c
 *   Say you have an array for which the `i-th` element is the price of
 *   a given stock on day `i`.
 *
 *   Design an algorithm to find the maximum profit. You may complete as
 *   many transactions as you like (i.e., buy one and sell one share of
 *   the stock multiple times).
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
maxProfit(int *prices, int pricesSize)
{
    if (pricesSize == 0) {
        return 0;
    }

    int max = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] - prices[i - 1] > 0) {
            max += (prices[i] - prices[i - 1]);
        }
    }

    return max;
}

int
maxProfit2(int *prices, int pricesSize)
{
    int max = 0;
    int valley;
    int peak;

    for (int i = 0; i < pricesSize - 1; i++) {
        while (i < pricesSize - 1 && prices[i] >= prices[i + 1]) {
            i++;
        }
        valley = prices[i];

        while (i < pricesSize - 1 && prices[i] <= prices[i + 1]) {
            i++;
        }
        peak = prices[i];

        max += (peak - valley);
    }

    return max;
}
