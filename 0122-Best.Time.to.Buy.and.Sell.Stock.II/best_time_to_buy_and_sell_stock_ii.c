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
#include <stdlib.h>

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

typedef struct {
    int hold;
    int unhold;
} stock_profit;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int
dpMaxProfit(int *prices, int pricesSize)
{
    stock_profit *dp;

    dp = (stock_profit *) malloc(sizeof(stock_profit) * pricesSize);

    dp[0].hold = -prices[0];
    dp[0].unhold = 0;

    for (int i = 1; i < pricesSize; i++) {
        dp[i].hold = MAX(dp[i-1].hold, dp[i-1].unhold - prices[i]);
        dp[i].unhold = MAX(dp[i-1].hold + prices[i], dp[i-1].unhold);
    }

    return dp[pricesSize-1].unhold;
}

int
dpMaxProfit2(int *prices, int pricesSize)
{
    int hold = -prices[0];
    int unhold = 0;

    for (int i = 1; i < pricesSize; i++) {
        hold = MAX(hold, unhold - prices[i]);
        unhold = MAX(hold + prices[i], unhold);
    }

    return unhold;
}

int
greedyMaxProfit(int *prices, int pricesSize)
{
    int max_profit = 0;

    for (int i = pricesSize - 1; i > 0; i--) {
        int profit = prices[i] - prices[i-1];
        if (profit > 0) {
            max_profit += profit;
        }
    }

    return max_profit;
}
