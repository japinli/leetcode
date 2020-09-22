/*----------------------------------------------------------------------------
 *
 * remove_all_adjacent_duplicates_in_string.c
 *   Given a string `S` of lowercase letters, a duplicate removal consists of
 *   choosing two adjacent and equal letters, and removing them.
 *
 *   We repeatedly make duplicate removals on S until we no longer can.
 *
 *   Return the final string after all such duplicate removals have been made.
 *   It is guaranteed the answer is unique.
 *
 *----------------------------------------------------------------------------
 */

char *
removeDuplicates(char *S)
{
    int   top = -1;
    char *stack = S;

    while (*S) {
        if (top == -1) {
            stack[++top] = *S;
        } else if (stack[top] == *S) {
            top--;
        } else {
            stack[++top] = *S;
        }
        S++;
    }

    stack[top + 1] = '\0';

    return stack;
}
