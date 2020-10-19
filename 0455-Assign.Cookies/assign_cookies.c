/*----------------------------------------------------------------------------
 *
 * assign_cookies.c
 *   Assume you are an awesome parent and want to give your children some
 *   cookies. But, you should give each child at most one cookie.
 *
 *   Each child `i` has a greed factor `g[i]`, which is the minimum size of a
 *   cookie that the child will be content with; and each cookie `j` has a
 *   size `s[j]`. If `s[j] >= g[i]`, we can assign the cookie `j` to the
 *   child `i`, and the child `i` will be content. Your goal is to maximize
 *   the number of your content children and output the maximum number.
 *
 *----------------------------------------------------------------------------
 */

#include <stdlib.h>

static int
cmp(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int
findContentChildren(int *g, int gSize, int *s, int sSize)
{
    int children = 0;

    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);

    for (int j = 0; children < gSize && j < sSize; j++) {
        if (g[children] <= s[j]) {
            children++;
        }
    }

    return children;
}
