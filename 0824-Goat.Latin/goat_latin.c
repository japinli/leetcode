/*----------------------------------------------------------------------------
 *
 * goat_latin.c
 *   A sentence `S` is given, composed of words separated by spaces.
 *   Each word consists of lowercase and uppercase letters only.
 *
 *   We would like to convert the sentence to "Goat Latin" (a made-up
 *   language similar to Pig Latin.)
 *
 *   The rules of Goat Latin are as follows:
 *
 *     1. If a word begins with a vowel (a, e, i, o, or u), append
 *        `"ma"` to the end of the word.
 *        For example, the word 'apple' becomes 'applema'.
 *
 *     2. If a word begins with a consonant (i.e. not a vowel), remove
 *        the first letter and append it to the end, then add "ma".
 *        For example, the word "goat" becomes "oatgma".
 *
 *     3. Add one letter 'a' to the end of each word per its word index
 *        in the sentence, starting with 1.
 *        For example, the first word gets "a" added to the end, the
 *        second word gets "aa" added to the end and so on.
 *
 *   Return the final sentence representing the conversion from `S` to
 *   Goat Latin.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static bool
isVowel(char letter)
{
    static char vowel[] = "aeiouAEIOU";

    char *found = strchr(vowel, letter);

    return found != NULL;
}

/*
 * We assume that the string do not end up with space.
 */
char *
toGoatLatin(char *S)
{
    /* make sure we have enough space for this problem */
    static char result[65535];

    int         word_count = 0;
    int         residx = 0;
    bool        first_letter = true;
    bool        is_vowel;
    char        save_char;

    while (*S) {
        if (first_letter) {
            first_letter = false;

            is_vowel = isVowel(*S);
            if (is_vowel) {
                result[residx++] = *S;
            } else {
                save_char = *S;
            }
        } else if (*S == ' ') {
            word_count++;    /* find a new word */
            first_letter = true;

            if (!is_vowel) {
                result[residx++] = save_char;
            }
            result[residx++] = 'm';
            result[residx++] = 'a';

            for (int i = 0; i < word_count; i++) {
                result[residx++] = 'a';
            }

            result[residx++] = *S;  /* do not forget the space */
        } else {
            result[residx++] = *S;
        }
        S++;
    }

    /* Now, we handle the last word. */
    word_count++;  /* '\0' produce a new word */
    if (!is_vowel) {
        result[residx++] = save_char;
    }
    result[residx++] = 'm';
    result[residx++] = 'a';

    for (int i = 0; i < word_count; i++) {
        result[residx++] = 'a';
    }

    result[residx++] = *S; /* copy '\0' to end this string */

    return result;
}
