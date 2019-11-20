/*----------------------------------------------------------------------------
 *
 * number_of_segments_in_a_string.c
 *   Count the number of segments in a string, where a segment is
 *   defined to be a contiguous sequence of non-space characters.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

int
countSegments(char *s)
{
    int segments = 0;
    int non_space = 0;

    while (*s) {
        if (*s++ == ' ') {
            segments += non_space;
            non_space = 0;

            while (*s == ' ') {
                s++;
            }
        } else {
            non_space = 1;
        }
    }

    /* do not forget the last one */
    segments += non_space;

    return segments;
}
