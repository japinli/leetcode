/*----------------------------------------------------------------------------
 *
 * isomorphic_strings.c
 *   Given two strings `s` and `t`, determine if they are isomorphic.
 *
 *   Two strings are isomorphic if the characters in `s` can be replaced
 *   to get `t`.
 *
 *   All occurrences of a character must be replaced with another
 *   character while preserving the order of characters. No two
 *   characters may map to the same character but a character may map to
 *   itself.
 *
 *----------------------------------------------------------------------------
 */


bool
isIsomorphic(char *s, char *t)
{
    char    aux1[256] = { 0 };
    char    aux2[256] = { 0 };

    while (*s) {
        if (aux1[*s] == 0 && aux2[*t] == 0) {
            aux1[*s] = *t;
            aux2[*t] = *t;
        } else {
            if (aux1[*s] != *t || aux2[*t] != *t) {
                return false;
            }
        }
        s++, t++;
    }
    return true;
}
