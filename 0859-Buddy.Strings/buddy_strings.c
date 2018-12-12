/*----------------------------------------------------------------------------
 *
 * buddy_strings.c
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool
buddyStrings(char *A, char *B)
{
    size_t len1 = strlen(A);
    size_t len2 = strlen(B);
    int count[26] = { 0 };

    if (len1 != len2 || len1 == 0) {
        return false;
    }

    size_t l = 0, r = len1 - 1;

    while (l < len1 && A[l] == B[l]) {
        count[A[l] - 'a']++;
        l++;
    }

    if (l == len1) {
        for (int i = 0; i < 26; i++) {
            if (count[i] > 1) {
                return true;
            }
        }
    }

    while (l < r && A[r] == B[r]) {
        r--;
    }

    return l != r && A[l] == B[r] && A[r] == B[l];
}
