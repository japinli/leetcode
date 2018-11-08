/*----------------------------------------------------------------------------
 *
 * rotate_array.c
 *   Given an array, rotate the array to the right by `k` steps, where
 *   `k` is non-negative.
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>

static void
reverse(int *nums, int l, int h)
{
    int t;
    while (l < h) {
        t = nums[l];
        nums[l] = nums[h];
        nums[h] = t;
        l++, h--;
    }
}

void
rotate(int *nums, int numsSize, int k)
{
    if (numsSize < 2 || (k = k % numsSize) == 0) {
        return;
    }

    reverse(nums, 0, numsSize - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, numsSize - 1);
}

static void
shiftOne(int *nums, int numsSize)
{
    int t = nums[numsSize - 1];

    for (int i = numsSize - 1; i > 0; i--) {
        nums[i] = nums[i - 1];
    }
    nums[0] = t;
}


void
rotate2(int *nums, int numsSize, int k)
{
    if (numsSize < 2 || (k = k % numsSize) == 0) {
        return;
    }

    while (k--) {
        shiftOne(nums, numsSize);
    }
}

void
rotate3(int *nums, int numsSize, int k)
{
    if (numsSize < 2 || (k = k % numsSize) == 0) {
        return;
    }

    for (int start = 0, count = 0; count < numsSize; start++) {
        int current = nums[start];
        int index = start;

        do {
            index = (index + k) % numsSize;
            int tmp = nums[index];
            nums[index] = current;
            current = tmp;
            count++;
        } while (index != start);
    }
}
