/*----------------------------------------------------------------------------
 *
 * height_checker.c
 *   Students are asked to stand in non-decreasing order of heights for
 *   an annual photo.
 *
 *   Return the minimum number of students that must move in order for
 *   all students to be standing in non-decreasing order of height.
 *
 *   Notice that when a group of students is selected they can reorder
 *   in any possible way between themselves and the non selected
 *   students remain on their seats.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>
#include <string.h>

static int
compareInt(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int
heightChecker(int *heights, int heightsSize)
{
    int  moved = 0;
    int *tmp = (int *) malloc(sizeof(int) * heightsSize);
    memcpy(tmp, heights, sizeof(int) * heightsSize);

    qsort(tmp, heightsSize, sizeof(int), compareInt);

    for (int i = 0; i < heightsSize; i++) {
        if (tmp[i] != heights[i]) {
            moved++;
        }
    }

    free(tmp);
    return moved;
}
