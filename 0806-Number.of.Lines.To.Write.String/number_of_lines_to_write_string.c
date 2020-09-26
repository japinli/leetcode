/*----------------------------------------------------------------------------
 *
 * number_of_lines_to_write_string.c
 *   We are to write the letters of a given string `S`, from left to right
 *   into lines. Each line has maximum width 100 units, and if writing a
 *   letter would cause the width of the line to exceed 100 units, it is
 *   written on the next line. We are given an array widths, an array where
 *   `widths[0]` is the width of 'a', widths[1] is the width of 'b', ..., and
 *   widths[25] is the width of 'z'.
 *
 *   Now answer two questions: how many lines have at least one character
 *   from `S`, and what is the width used by the last such line? Return your
 *   answer as an integer list of length 2.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

int *
numberOfLines(int *widths, int widthsSize, char *S, int *returnSize)
{
    int  w = 0;
    int  lines = 1;
    int *res = (int *) malloc(sizeof(int) * 2);

    while (*S) {
        w += widths[*S - 'a'];
        if (w > 100) {
            lines++;
            w = widths[*S - 'a'];
        }
        S++;
    }

    res[0] = lines;
    res[1] = w;
    *returnSize = 2;
    return res;
}
