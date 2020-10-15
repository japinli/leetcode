/*----------------------------------------------------------------------------
 *
 * last_stone_weight.c
 *   We have a collection of stones, each stone has a positive integer weight.
 *
 *   Each turn, we choose the two __heaviest__ stones and smash them together.
 *   Suppose the stones have weights `x` and `y` with `x <= y`.  The result of
 *   this smash is:
 *
 *   * If `x == y`, both stones are totally destroyed;
 *   * If `x != y`, the stone of weight `x` is totally destroyed, and the
 *     stone of weight `y` has new weight `y-x`.
 *
 *   At the end, there is at most 1 stone left.  Return the weight of this
 *   stone (or 0 if there are no stones left.)
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

static int
cmp(const void *a, const void *b)
{
    return *(int *) b - *(int *) a;
}

int
lastStoneWeight(int *stones, int stonesSize)
{
    int num = stonesSize;

    while (num > 1) {
        qsort(stones, stonesSize, sizeof(int), cmp);
        stonesSize = num;  /* reduce the sorting number */
        if (stones[0] == stones[1]) {
            stones[0] = 0;
            num--;
        } else {
            stones[0] -= stones[1];
        }
        stones[1] = 0;
        num--;
    }

    /* do not forget sort the stones */
    qsort(stones, stonesSize, sizeof(int), cmp);

    return stones[0];
}
