/*----------------------------------------------------------------------------
 *
 * minimum_time_visiting_all_points.c
 *   On a plane there are `n` points with integer coordinates
 *   `points[i] = [xi, yi]`. Your task is to find the minimum time in seconds
 *   to visit all points.
 *
 *   You can move according to the next rules:
 *
 *     * In one second always you can either move vertically, horizontally
 *       by one unit or diagonally (it means to move one unit vertically
 *       and one unit horizontally in one second).
 *     * You have to visit the points in the same order as they appear in
 *       the array.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

int
minTimeToVisitAllPoints(int **points, int pointsSize, int *pointsColSize)
{
    int seconds = 0;

    for (int i = 1; i < pointsSize; i++) {
        int x = points[i][0] - points[i - 1][0];
        int y = points[i][1] - points[i - 1][1];

        x = x >= 0 ? x : -x;
        y = y >= 0 ? y : -y;

        seconds += (x > y) ? x : y;
    }

    return seconds;
}
