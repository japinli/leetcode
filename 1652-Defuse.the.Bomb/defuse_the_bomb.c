/*----------------------------------------------------------------------------
 *
 * defuse_the_bomb.c
 *   You have a bomb to defuse, and your time is running out! Your informer
 *   will provide you with a circular array `code` of length of `n` and a
 *   key `k`.
 *
 *   To decrypt the code, you must replace every number. All the numbers are
 *   replaced simultaneously.
 *
 *   - If `k > 0`, replace the `i-th` number with the sum of the next
 *     `k` numbers.
 *   - If `k < 0`, replace the `i-th` number with the sum of the previous
 *     `k` numbers.
 *   - If `k == 0`, replace the `i-th` number with `0`.
 *
 *   As `code` is circular, the next element of `code[n-1]` is `code[0]`,
 *   and the previous element of `code[0]` is `code[n-1]`.
 *
 *   Given the circular array `code` and an integer key `k`, return the
 *   decrypted code to defuse the bomb!
 *
 *----------------------------------------------------------------------------
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *
decrypt(int *code, int codeSize, int k, int *returnSize)
{
    int  s = 1;
    int  e = k;
    int *res = (int *) calloc(codeSize, sizeof(int));

    *returnSize = codeSize;
    if (k == 0) {
        return res;
    }

    if (k < 0) {
        k = -k;
        s = codeSize - k;
        e = codeSize - 1;
    }

    for (int i = s; i <= e; i++) {
        res[0] += code[i];
    }
    
    for (int i = 1; i < codeSize; i++) {
        res[i] = res[i - 1] - code[(s++) % codeSize] + code[(++e) % codeSize];
    }

    return res;
}