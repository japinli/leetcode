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
