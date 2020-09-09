/*----------------------------------------------------------------------------
 *
 * destination_city.c
 *   You are given the array `paths`, where `paths[i] = [cityAi, cityBi]`
 *   means there exists a direct path going from `cityAi` to `cityBi`.
 *   Return the destination city, that is, the city without any path
 *   outgoing to another city.
 *
 *   It is guaranteed that the graph of paths forms a line without any
 *   loop, therefore, there will be exactly one destination city.
 *
 *----------------------------------------------------------------------------
 */
#include <string.h>

#if 0
char *
destCity(char ***paths, int pathsSize, int *pathsColSize)
{
    for (int i = 0; i < pathsSize; i++) {
        char *dest = paths[i][1];
        int j;
        for (j = 0; j < pathsSize; j++) {
            char *start = paths[j][0];
            if (strcmp(dest, start) == 0) {
                break;
            }
        }

        if (j == pathsSize) {
            return dest;
        }
    }

    return NULL;
}
#endif


char *
destCity(char ***paths, int pathsSize, int *pathsColSize)
{
    char *dest = paths[0][1];
    for (int i = 0; i < pathsSize; i++) {
        if (strcmp(dest, paths[i][0]) == 0) {
            dest = paths[i][1];
            i = 0;
        }
    }

    return dest;
}
