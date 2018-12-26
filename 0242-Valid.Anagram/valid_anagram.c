/*----------------------------------------------------------------------------
 *
 * valid_anagram.c
 *   Given two strings `s` and `t` , write a function to determine if
 *   `t` is an anagram of `s`.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

static int
compare(const void *a, const void *b)
{
    return *(char *) a - *(char *) b;
}

bool
isAnagram2(char *s, char *t)
{
    size_t len1 = strlen(s);
    size_t len2 = strlen(t);

    qsort(s, len1, sizeof(char), compare);
    qsort(t, len2, sizeof(char), compare);

    return strcmp(s, t) == 0;
}


bool
isAnagram(char *s, char *t)
{
    int cnt[26] = { 0 };

    while (*s) {
        if (*s >= 'a' && *s <= 'z') {
            cnt[*s - 'a']++;
        }
        s++;
    }

    while (*t) {
        if (*t >= 'a' && *t <= 'z') {
            cnt[*t - 'a']--;
        }
        t++;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            return false;
        }
    }

    return true;
}
