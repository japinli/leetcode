/*----------------------------------------------------------------------------
 *
 * min_cost_climbing_stairs.c
 *  On a staircase, the `i-th` step has some non-negative cost `cost[i]`
 *  assigned (0 indexed).
 *
 *  Once you pay the cost, you can either climb one or two steps. You
 *  need to find minimum cost to reach the top of the floor, and you can
 *  either start from the step with index 0, or the step with index 1.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

#define MIN(a, b)    ((a) < (b) ? (a) : (b))

int
minCostClimbingStairs(int *cost, int costSize)
{
    int f0, f1, f2;

    f1 = f2 = 0;

    for (int i = 0; i < costSize; i++) {
        f0 = cost[i] + MIN(f1, f2);
        f2 = f1;
        f1 = f0;
    }

    return MIN(f1, f2);
}
