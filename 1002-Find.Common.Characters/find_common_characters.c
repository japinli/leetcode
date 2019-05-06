/*----------------------------------------------------------------------------
 *
 * find_common_characters.c
 *   Given an array `A` of strings made only from lowercase letters,
 *   return a list of all characters that show up in all strings within
 *   the list (__including duplicates__).  For example, if a character
 *   occurs 3 times in all strings but not 4 times, you need to include
 *   that character three times in the final answer.
 *
 *   You may return the answer in any order.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>
#include <string.h>

char **
commonChars(char **A, int ASize, int *returnSize)
{
    int flags[ASize][26];

    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < 26; j++) {
            flags[i][j] = 0;
        }
    }

    for (int i = 0; i < ASize; i++) {
        size_t len = strlen(A[i]);
        for (size_t j = 0; j < len; j++) {
            flags[i][A[i][j] - 'a']++;
        }
    }

    char **result = (char **) malloc(sizeof(char *) * 100);
    *returnSize = 0;

    for (int j = 0; j < 26; j++) {
        int min = 0x7FFFFFFF;
        for (int i = 0; i < ASize; i++) {
            min = min < flags[i][j] ? min : flags[i][j];
        }

        while (min--) {
            result[*returnSize] = (char *) malloc(sizeof(char) * 2);
            result[*returnSize][0] = 'a' + j;
            result[*returnSize][1] = '\0';
            (*returnSize)++;
        }
    }

    return result;
}
