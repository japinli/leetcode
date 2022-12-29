/*----------------------------------------------------------------------------
 *
 * count_sorted_vowel_strings.c
 *   Given an integer `n`, return the number of strings of length `n` that
 *   consist only of vowels `(a, e, i, o, u)` and are lexicographically
 *   sorted.
 *
 *   A string s is lexicographically sorted if for all valid `i, s[i]` is the
 *   same as or comes before `s[i+1]` in the alphabet.
 *
 *----------------------------------------------------------------------------
 */

int
countVowelStrings(int n)
{
    int dp[] = { 0, 1, 1, 1, 1, 1};

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 6; j++) {
            dp[j] += dp[j - 1];
        }
    }

    return dp[5];
}
