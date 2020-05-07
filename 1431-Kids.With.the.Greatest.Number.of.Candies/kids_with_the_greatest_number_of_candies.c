/*----------------------------------------------------------------------------
 *
 * kids_with_the_greatest_number_of_candies.c
 *   Given the array `candies` and the integer `extraCandies`, where
 *   `candies[i]` represents the number of candies that the ith kid has.
 *
 *   For each kid check if there is a way to distribute `extraCandies`
 *   among the kids such that he or she can have the `greatest` number
 *   of candies among them. Notice that multiple kids can have the
 *   `greatest` number of candies.
 *
 *----------------------------------------------------------------------------
 */
#include <stdbool.h>
#include <stdlib.h>

bool *
kidsWithCandies(int *candies, int candiesSize, int extraCandies, int *returnSize)
{
    int   greatest = -1;
    bool *result = (bool *) malloc(sizeof(bool) * candiesSize);
    *returnSize = candiesSize;

    for (int i = 0; i < candiesSize; i++) {
        if (greatest < candies[i]) {
            greatest = candies[i];
        }
    }

    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] + extraCandies >= greatest) {
            result[i] = true;
        } else {
            result[i] = false;
        }
    }

    return result;
}
