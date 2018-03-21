/*----------------------------------------------------------------------------
 *
 * Jewels and stones.
 *
 * gcc -o jewels_stones jewels_stones.c
 *
 *----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>

#define unused(expr) ((void) (expr))

/* Brute force
int
numJewelsInStones(char* J, char* S)
{
    size_t len1 = strlen(J);
    size_t len2 = strlen(S);
    size_t len = 0;

    if (len1 == 0) {
        return len;
    }

    for (size_t i = 0; i < len1; ++i) {
        for (size_t j = 0; j < len2; ++j) {
            if (J[i] == S[j]) {
                len++;
            }
        }
    }

    return len;
}
*/

int
numJewelsInStones(char* J, char* S)
{
    size_t len1 = strlen(J);
    size_t len2 = strlen(S);
    size_t len = 0;
    int bucket[256] = {0};

    if (len1 == 0) {
        return len;
    }

    for (size_t i = 0; i < len2; ++i) {
        bucket[(int) S[i]] ++;
    }

    for (size_t i = 0; i < len1; ++i) {
        len += bucket[(int) J[i]];
    }

    return len;
}

int
main(int argc, char *argv[])
{
    char A[100], B[100];

    unused(argc); unused(argv);

    while (scanf("%s%s", A, B) != EOF) {
        printf("%s %s -> ", A, B);
        printf("%d\n", numJewelsInStones(A, B));
    }

    return 0;
}
