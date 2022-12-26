/*----------------------------------------------------------------------------
 *
 * best_time_to_buy_and_sell_stock.c
 *   Say you have an array for which the `i-th` element is the price of
 *   a given stock on day `i`.
 *
 *   If you were only permitted to complete at most one transaction
 *   (i.e., buy one and sell one share of the stock), design an
 *   algorithm to find the maximum profit.
 *
 *   Note that you cannot sell a stock before you buy one.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b)    ((a) > (b) ? (a) : (b))

static int
maxProfitHelper(int *prices, int l, int h)
{
    if (l == h) {
        return prices[l];
    } else if (l + 1 == h) {
        return MAX(prices[l], MAX(prices[h], prices[l] + prices[h]));
    }

    int m = (l + h) >> 1;
    int left = maxProfitHelper(prices, l, m - 1);
    int right = maxProfitHelper(prices, m + 1, h);
    int max = prices[m];
    int sum = max;
    for (int i = m - 1; i >= l; i--) {
        sum += prices[i];
        max = MAX(max, sum);
    }

    sum = max;
    for (int i = m + 1; i <= h; i++) {
        sum += prices[i];
        max = MAX(max, sum);
    }

    return MAX(max, MAX(left, right));
}

int
maxProfit(int *prices, int pricesSize)
{
    if (pricesSize == 0) {
        return 0;
    }

    for (int i = pricesSize - 1; i > 0; i--) {
        prices[i] -= prices[i - 1];
    }
    prices[0] = 0;

    return maxProfitHelper(prices, 0, pricesSize - 1);
}

typedef struct {
    int hold;
    int unhold;
} stock_profit;

int
dpMaxProfit(int *prices, int pricesSize)
{
    stock_profit *dp;
    int max_profit;

    dp = (stock_profit *) malloc(sizeof(stock_profit) * pricesSize);

    dp[0].hold = -prices[0];
    dp[0].unhold = 0;

    for (int i = 1; i < pricesSize; i++) {
        dp[i].hold = MAX(dp[i-1].hold, -prices[i]);
        dp[i].unhold = MAX(dp[i-1].hold + prices[i], dp[i-1].unhold);
    }

    max_profit = dp[pricesSize - 1].unhold;
    free(dp);

    return max_profit;
}

int
dpMaxProfit1(int *prices, int pricesSize)
{
    int hold = -prices[0];
    int unhold = 0;

    for (int i = 0; i < pricesSize; i++) {
        hold = MAX(hold, -prices[i]);
        unhold = MAX(unhold, hold + prices[i]);
    }

    return unhold;
}

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int
greedyMaxProfit(int *prices, int pricesSize)
{
    int max_profit = 0;
    int min_prices = prices[0];

    for (int i = 1; i < pricesSize; i++) {
        min_prices = MIN(min_prices, prices[i]);
        max_profit = MAX(max_profit, prices[i] - min_prices);
    }

    return max_profit;
}
