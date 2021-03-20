/*----------------------------------------------------------------------------
 *
 * string_matching_in_an_array.c
 *   Given an array of string `words`. Return all strings in `words` which
 *   is substring of another word in any order. 
 *
 *   String `words[i]` is substring of `words[j]`, if can be obtained
 *   removing some characters to left and/or right side of `words[j]`.
 *
 *----------------------------------------------------------------------------
 */

char **
stringMatching(char **words, int wordsSize, int *returnSize)
{
    char **res = (char **) malloc(sizeof(char *) * wordsSize);
    int count = 0;

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < wordsSize; j++) {
            if (i != j && strstr(words[j], words[i]) != NULL) {
                res[count++] = words[i];
                break;
            }
        }
    }

    *returnSize = count;
    return res;
}