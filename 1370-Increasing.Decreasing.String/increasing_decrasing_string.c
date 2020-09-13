/*----------------------------------------------------------------------------
 *
 * increasing_decrasing_string.c
 *   Given a string `s`. You should re-order the string using the
 *   following algorithm:
 *
 *   1. Pick the __smallest__ character from `s` and __append__ it to
 *      the result.
 *   2. Pick the __smallest__ character from `s` which is greater than
 *      the last appended character to the result and __append__ it.
 *   3. Repeat step 2 until you cannot pick more characters.
 *   4. Pick the __largest__ character from `s` and __append__ it to
 *      the result.
 *   5. Pick the __largest__ character from `s` which is smaller than
 *      the last appended character to the result and __append__ it.
 *   6. Repeat step 5 until you cannot pick more characters.
 *   7. Repeat the steps from 1 to 6 until you pick all characters from `s`.
 *
 *   In each step, if the smallest or the largest character appears more
 *   than once you can choose any occurrence and append it to the result.
 *
 *   Return _the result string_ after sorting `s` with this algorithm.
 *
 *----------------------------------------------------------------------------
 */
#include <string.h>

char *
sortString(char * s)
{
    int ht[26] = { 0 };
    size_t len = strlen(s);
    size_t i;

    for ( i = 0; i < len; i++) {
        ht[s[i] - 'a']++;
    }

    i = 0;
    while (i < len) {
        for (int j = 0; j <= 25; j++) {
            if (ht[j]) {
                s[i++] = 'a' + j;
                ht[j]--;
            }
        }
        for (int j = 25; j >= 0; j--) {
            if (ht[j]) {
                s[i++] = 'a' + j;
                ht[j]--;
            }
        }
    }

    return s;
}
