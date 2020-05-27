/*----------------------------------------------------------------------------
 *
 * count_largest_group.c
 *   Given an integer `n`. Each number from `1` to `n` is grouped
 *   according to the sum of its digits.
 *
 *   Return how many groups have the largest size.
 *
 *----------------------------------------------------------------------------
 */

static inline int
sumOfDigits(int n)
{
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int
countLargestGroup(int n)
{
    int ht[40] = { 0 };    /* the maximum is 9 + 9 + 9 + 9 = 36 */
    int max = -1;
    int idx;
    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        idx = sumOfDigits(i);
        ht[idx]++;
        if (max < ht[idx]) {
            max = ht[idx];
        }
    }

    for (int i = 0; i < 40; i++) {
        if (max == ht[i]) {
            cnt++;
        }
    }

    return cnt;
}
