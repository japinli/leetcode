/*----------------------------------------------------------------------------
 *
 * decrypt_string_from_alphabet_to_integer_mapping.c
 *     Given a string s formed by digits (`'0'` - `'9'`) and `'#'`. We want
 *     to map `s` to English lowercase characters as follows:
 *
 *     - Characters (`'a'` to `'i'`) are represented by (`'1'` to `'9'`)
 *       respectively.
 *     - Characters (`'j'` to `'z'`) are represented by (`'10#'` to `'26#'`)
 *        respectively.
 *
 *     Return the string formed after mapping.
 *
 *     It's guaranteed that a unique mapping will always exist.
 *
 *----------------------------------------------------------------------------
 */
#include <string.h>

char *
freqAlphabets(char *s)
{
    size_t len = strlen(s);
    size_t i, j;

    i = j = 0;

    while (i < len) {
        int idx;
        if (i + 2 < len && s[i + 2] == '#') {
            idx = (s[i] - '0') * 10 + (s[i + 1] - '0');
            i += 3;
        } else {
            idx = s[i++] - '0';
        }

        s[j++] = 'a' + idx - 1;
    }

    s[j] = '\0';

    return s;
}
