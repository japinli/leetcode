/*----------------------------------------------------------------------------
 *
 * prime_number_of_set_bits_in_binary_representation.c
 *   Given two integers `L` and `R`, find the count of numbers in the range
 *   `[L, R]` (inclusive) having a prime number of set bits in their binary
 *   representation.
 *
 *   (Recall that the number of set bits an integer has is the number of
 *   `1`s present when written in binary. For example, `21` written in
 *   binary is `10101` which has `3` set bits. Also, `1` is not a prime.)
 * 
 *----------------------------------------------------------------------------
 */
static inline int
countBits(int n)
{
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0F0F0F0F) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    
    return n;
}

int 
countPrimeSetBits(int L, int R)
{
    int hash[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0};
    int count = 0;

    for (int i = L; i <= R; i++) {
        if (hash[countBits(i)]) {
            count++;
        }
    }

    return count;
}