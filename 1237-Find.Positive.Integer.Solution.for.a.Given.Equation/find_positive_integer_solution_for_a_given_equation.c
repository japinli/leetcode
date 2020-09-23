/*----------------------------------------------------------------------------
 *
 * find_positive_integer_solution_for_a_given_equation.c
 *   Given a function `f(x, y)` and a value `z`, return all positive integer
 *   pairs `x` and `y` where `f(x,y) == z`.
 *
 *   The function is constantly increasing, i.e.:
 *
 *   * `f(x, y) < f(x + 1, y)`
 *   * `f(x, y) < f(x, y + 1)`
 *
 *   The function interface is defined like this:
 *
 *   ```
 *   interface CustomFunction {
 *   public:
 *     // Returns positive integer f(x, y) for any given positive integer x and y.
 *     int f(int x, int y);
 *   };
 *   ```
 *
 *   For custom testing purposes you're given an integer `function_id` and a
 *   target `z` as input, where `function_id` represent one function from an
 *   secret internal list, on the examples you'll know only two functions
 *   from the list.
 *
 *   You may return the solutions in any order.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>

/*
 * // This is the definition for customFunction API.
 * // You should not implement it, or speculate about its implementation
 *
 * // Returns f(x, y) for any given positive integers x and y.
 * // Note that f(x, y) is increasing with respect to both x and y.
 * // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 */

/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int **
findSolution(int (*customFunction)(int, int), int z,
             int *returnSize, int **returnColumnSizes)
{
	int x = 1;
    int y = z;
    int idx = 0;
    int cap = z;
    int **result = (int **) malloc(sizeof(int *) * cap);
    int *columnSizes = (int *) malloc(sizeof(int) * cap);

    while (x <= z && y > 0) {
        int t = customFunction(x, y);
        if (z == t) {
            if (idx == cap) {
                cap *= 2;
                result = (int **) realloc(result, cap);
                columnSizes = (int *) realloc(columnSizes, cap);
            }
            result[idx] = (int *) malloc(sizeof(int) * 2);
            result[idx][0] = x;
            result[idx][1] = y;
            columnSizes[idx] = 2;
            idx++;
            x++;
        } else if (t < z) {
            x++;
        } else {
            y--;
        }
    }

    *returnSize = idx;
    *returnColumnSizes = columnSizes;
    return result;
}
