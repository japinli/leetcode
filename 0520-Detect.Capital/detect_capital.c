/*----------------------------------------------------------------------------
 *
 * detect_capital.c
 *   Given a word, you need to judge whether the usage of capitals in it
 *   is right or not.
 *
 *   We define the usage of capitals in a word to be right when one of
 *   the following cases holds:
 *
 *     1. All letters in this word are capitals, like "USA".
 *     2. All letters in this word are not capitals, like "leetcode".
 *     3. Only the first letter in this word is capital if it has more
 *        than one letter, like "Google".
 *
 *   Otherwise, we define that this word doesn't use capitals in a right
 *   way.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool
detectCapitalUse(char *word)
{
    int len = strlen(word);

    if (len == 1) {
        return true;
    }

    bool capital = (*word >= 'A' && *word <= 'Z');
    word++;

    bool lower = false;
    bool upper = false;

    while (*word) {
        if (*word >= 'A' && *word <= 'Z') {
            upper = true;
        } else if (*word >= 'a' && *word <= 'z') {
            lower = true;
        }

        if (lower && upper) {
            return false;
        }

        word++;
    }

    if (!capital && upper) {
        return false;
    }

    return true;
}
