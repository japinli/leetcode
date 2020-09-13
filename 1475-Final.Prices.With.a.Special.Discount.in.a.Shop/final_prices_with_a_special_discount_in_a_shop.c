/*----------------------------------------------------------------------------
 *
 * final_prices_with_a_special_discount_in_a_shop.c
 *   Given the array `prices` where `prices[i]` is the price of the `ith`
 *   item in a shop. There is a special discount for items in the shop, if
 *   you buy the `ith` item, then you will receive a discount equivalent to
 *   `prices[j]` where `j` is the __minimum__ index such that `j > i` and
 *   `prices[j] <= prices[i]`, otherwise, you will not receive any discount
 *   at all.
 *
 *   Return an array where the `ith` element is the final price you will pay
 *   for the `ith` item of the shop considering the special discount.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>


static int
getDiscount(int *prices, int start, int end, int price)
{
    while (start < end) {
        if (prices[start] <= price) {
            return price - prices[start];
        }
        start++;
    }

    return price;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
finalPrices(int *prices, int pricesSize, int *returnSize)
{
    int *res = (int *) malloc(sizeof(int) * pricesSize);

    for (int i = 0; i < pricesSize; i++) {
        res[i] = getDiscount(prices, i + 1, pricesSize, prices[i]);
    }

    *returnSize = pricesSize;
    return res;
}
