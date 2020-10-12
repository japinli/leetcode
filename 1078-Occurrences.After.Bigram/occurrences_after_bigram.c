/*----------------------------------------------------------------------------
 *
 * occurrences_after_bigram.c
 *   Given words `first` and `second`, consider occurrences in some `text` of
 *   the form "first second third", where `second` comes immediately after
 *   `first`, and `third` comes immediately after `second`.
 *
 *   For each such occurrence, add "third" to the answer, and return the
 *   answer.
 *
 *----------------------------------------------------------------------------
 */
#include <string.h>
#include <stdlib.h>

static inline char *
skip_leading_space(char *s)
{
    while (*s && *s == ' ') {
        s++;
    }

    return s;
}

static inline int
find_word_length(char *s)
{
    char *p = s;

    while (*p && *p != ' ') {
        p++;
    }

    return p - s;
}

char **
findOcurrences(char *text, char *first, char *second, int *returnSize)
{
    int cap = 2;
    char **res = (char **) malloc(sizeof(char *) * cap);
    char *one = text;
    char *two;
    size_t flen = strlen(first);
    size_t slen = strlen(second);
    size_t tlen = strlen(text);

    *returnSize = 0;

    one = skip_leading_space(one);
    while (*one && one + flen + slen < text + tlen) {

        if (strncmp(first, one, flen) == 0) {
            two = one + flen;
            two = skip_leading_space(two);
            if (strncmp(second, two, slen) == 0) {
                char *third = two + slen;
                third = skip_leading_space(third);
                if (*third) {
                    if (*returnSize >= cap) {
                        cap *= 2;
                        res = (char **) realloc(res, sizeof(char *) * cap);
                    }

                    res[*returnSize] = strndup(third, find_word_length(third));
                    (*returnSize)++;
                }
            }
        }
        one += find_word_length(one);
        one = skip_leading_space(one);
    }

    return res;
}
