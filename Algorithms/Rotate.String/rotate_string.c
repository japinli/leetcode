/*----------------------------------------------------------------------------
 *
 * Rotate string.
 *
 * gcc -o rotate_string rotate_string.c
 *
 *----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define unused(expr) ((void) (expr))

static void
shift_one(char *A, size_t len)
{
    char t = A[0];

    for (int i = 0; i < len - 1; ++i) {
        A[i] = A[i + 1];
    }
    A[len - 1] = t;
}

/*
bool
rotateString(char *A, char *B)
{
    size_t len1 = strlen(A);
    size_t len2 = strlen(B);
    int count = (int) len1;

    if (len1 != len2) {
        return false;
    }
    if (len1 == 0) {
        return true;
    }

    do {
        if (strcmp(A, B) == 0) {
            return true;
        }
        shift_one(A, len1);
    } while (--count > 0);

    return false;
}
*/

bool
rotateString(char *A, char *B)
{
    size_t len1 = strlen(A);
    size_t len2 = strlen(B);
    size_t s, i;

    if (len1 != len2) {
        return false;
    }
    if (len1 == 0) {
        return true;
    }

    for (s = 0; s < len1; ++s) {
        for (i = 0; i < len1; ++i) {
            if (A[(s+i) % len1] != B[i]) {
                break;
            }
        }

        if (i == len1) {
            return true; /* Here, we found a match. */
        }
    }

    return false;
}

int
main(int argc, char *argv[])
{
    char A[100], B[100];

    unused(argc); unused(argv);

    while (scanf("%s%s", A, B) != EOF) {
        printf("%s %s -> ", A, B);
        printf("%s\n", rotateString(A, B) ? "true" : "false");
    }

    return 0;
}
