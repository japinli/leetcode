/*----------------------------------------------------------------------------
 *
 * can_place_flowers.c
 *   Suppose you have a long flowerbed in which some of the plots are
 *   planted and some are not. However, flowers cannot be planted in
 *   adjacent plots - they would compete for water and both would die.
 *
 *   Given a flowerbed (represented as an array containing 0 and 1,
 *   where 0 means empty and 1 means not empty), and a number __n__,
 *   return if __n__ new flowers can be planted in it without violating
 *   the no-adjacent-flowers rule.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

bool
canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
    int *p = flowerbed;

    for (int i = 0; i < flowerbedSize; i++) {

        if ((i == 0 && p[i] == 0 && p[i + 1] == 0) ||
            (p[i - 1] == 0 && p[i] == 0 && p[i + 1] == 0) ||
            (i == flowerbedSize - 1 && p[i - 1] == 0 && p[i] == 0)) {
            n--;
            p[i] = 1;
        }
    }

    return n <= 0 ? true : false;
}
