/*----------------------------------------------------------------------------
 *
 * number_of_good_pairs.c
 *   Given an array of integers `nums`.
 *
 *   A pair `(i,j)` is called good if `nums[i] == nums[j] and i < j`.
 *
 *   Return the number of good pairs.
 *
 *----------------------------------------------------------------------------
 */
#if 0
int
numIdenticalPairs(int *nums, int numsSize)
{
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }
    }

    return count;
}
#endif

int
numIdenticalPairs(int *nums, int numsSize)
{
    int hash[101] = { 0 };
    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        hash[nums[i]]++;
    }

    for (int i = 1; i <= 100; i++) {
        sum += (hash[i] * (hash[i] - 1));
    }

    return sum >> 1;
}
