/*----------------------------------------------------------------------------
 *
 * baseball_game.c
 *   You're now a baseball game point recorder.
 *
 *   Given a list of strings, each string can be one of the 4 following
 *   types:
 *
 *     1. `Integer` (one round's score): Directly represents the number
 *        of points you get in this round.
 *     2. "+" (one round's score): Represents that the points you get in
 *        this round are the sum of the last two `valid` round's points.
 *     3. "D" (one round's score): Represents that the points you get in
 *        this round are the doubled data of the last `valid` round's
 *        points.
 *     4. "C" (an operation, which isn't a round's score): Represents
 *        the last `valid` round's points you get were invalid and
 *        should be removed.
 *
 *  Each round's operation is permanent and could have an impact on the
 *  round before and the round after.
 *
 *  You need to return the sum of the points you could get in all the
 *  rounds.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
calPoints(char **ops, int opsSize)
{
    int stack[1001] = {0};
    int top = -1;

    for (int i = 0; i < opsSize; i++) {
        if (strcmp(ops[i], "+") == 0) {
            stack[top + 1] = stack[top] + stack[top - 1];
            top++;
        } else if (strcmp(ops[i], "D") == 0) {
            stack[top + 1] = 2 * stack[top];
            top++;
        } else if (strcmp(ops[i], "C") == 0) {
            top--;
        } else {
            stack[++top] = atoi(ops[i]);
        }
    }

    int sum = 0;

    for (int i = 0; i <= top; i++) {
        sum += stack[i];
    }

    return sum;
}
