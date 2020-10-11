/*----------------------------------------------------------------------------
 *
 * keyboard_row.c
 *   Given a List of words, return the words that can be typed using letters
 *   of alphabet on only one row's of American keyboard like the image below.
 *
 *----------------------------------------------------------------------------
 */
#include <stdlib.h>
#include <string.h>

#if 0
int AuxTable[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 3, 4, 4, 3, 2, 3, 3, 3, 2, 3, 3, 3, 4, 4, 2,
    2, 2, 2, 3, 2, 2, 4, 2, 4, 2, 4, 0, 0, 0, 0, 0,
    0, 3, 4, 4, 3, 2, 3, 3, 3, 2, 3, 3, 3, 4, 4, 2,
    2, 2, 2, 3, 2, 2, 4, 2, 4, 2, 4, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};


static bool
inOneRow(const char *str)
{
    size_t len = strlen(str);

    for (size_t i = 1; i < len; i++) {
        if (AuxTable[(int)str[i - 1]] != AuxTable[(int)str[i]]) {
            return false;
        }

    }

    return true;
}

char **
findWords(char **words, int wordsSize, int *returnSize)
{
    int cap = 2;
    char **res = (char **) malloc(sizeof(char *) * cap);
    *returnSize = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (inOneRow(words[i])) {
            if (*returnSize >= cap) {
                cap *= 2;
                res = (char **) realloc(res, sizeof(char *) * cap);
            }

            res[*returnSize] = strdup(words[i]);
            (*returnSize)++;
        }
    }

    return res;
}

#endif

int RowIndex[] = {
    3, 4, 4, 3, 2, 3, 3, 3, 2, 3, 3, 3, 4, 4, 2,
    2, 2, 2, 3, 2, 2, 4, 2, 4, 2, 4
};

static inline int
getRow(char ch)
{
    if (ch >= 'A' && ch <= 'Z') {
        return RowIndex[(int)(ch - 'A')];
    }

    return RowIndex[(int)(ch - 'a')];
}

static bool
inOneRow(const char *str)
{
    int index = getRow(*str);

    str++;
    while (*str) {
        if (index != getRow(*str)) {
            return false;
        }
        str++;
    }

    return true;
}

char **
findWords(char **words, int wordsSize, int *returnSize)
{
    int cap = 2;
    char **res = (char **) malloc(sizeof(char *) * cap);
    *returnSize = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (inOneRow(words[i])) {
            if (*returnSize >= cap) {
                cap *= 2;
                res = (char **) realloc(res, sizeof(char *) * cap);
            }

            res[*returnSize] = strdup(words[i]);
            (*returnSize)++;
        }
    }

    return res;
}
