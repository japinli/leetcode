/*----------------------------------------------------------------------------
 *
 * find_words_that_can_be_formed_by_characters.c
 *   You are given an array of strings `words` and a string `chars`.
 *
 *   A string is good if it can be formed by characters from `chars`
 *   (each character can only be used once).
 *
 *   Return the sum of lengths of all good strings in `words`.
 *
 *----------------------------------------------------------------------------
 */

int
countCharacters(char **words, int wordsSize, char *chars)
{
    int ref[27] = { 0 };
    char *p = chars;
    int len = 0;

    while (*p) {
        ref[*p - 'a']++;
        p++;
    }

    for (int i = 0; i < wordsSize; i++) {
        int base[27] = { 0 };
        int l = 0;

        p = words[i];
        while (*p) {
            base[*p - 'a']++;
            p++;
        }

        l = p - words[i];
        for (int j = 0; j < 27; j++) {
            if (ref[j] < base[j]) {
                l = 0;
                break;
            }
        }

        len += l;
    }

    return len;
}
