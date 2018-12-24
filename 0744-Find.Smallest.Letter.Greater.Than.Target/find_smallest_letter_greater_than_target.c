/*----------------------------------------------------------------------------
 *
 * find_smallest_letter_greater_than_target.c
 *   Given a list of sorted characters letters containing only lowercase
 *   letters, and given a target letter target, find the smallest
 *   element in the list that is larger than the given target.
 *
 *   Letters also wrap around. For example, if the target is
 *   `target = 'z'` and `letters = ['a', 'b']`, the answer is `'a'`.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

char
nextGreatestLetter(char *letters, int lettersSize, char target)
{
    char ch = '\0';

    for (int i = 0; i < lettersSize; i++) {
        if (letters[i] > target) {
	    ch = letters[i];
	    break;
        }
    }

    return ch == '\0' ? letters[0] : ch;
}

char
nextGreatestLetter2(char *letters, int lettersSize, char target)
{
    int l = 0;
    int h = lettersSize;

    while (l < h) {
        int m = l + (h - l) / 2;

        if (letters[m] <= target) {
            l = m + 1;
        } else {
            h = m;
        }
    }

    return letters[l % lettersSize];
}
