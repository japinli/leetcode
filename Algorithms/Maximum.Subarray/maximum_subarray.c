/*----------------------------------------------------------------------------
 *
 * Maximum subarray
 *
 * gcc -o maximum_subarray maximum_subarray.c
 *
 *----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int
maxSubArray(int* nums, int numsSize) {
    int *dp = (int *) malloc(sizeof(int) * numsSize);
    int max = nums[0];
    dp[0] = nums[0];

    for (int i = 1; i < numsSize; i++) {
        dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
        max = MAX(dp[i], max);
    }
    
    return max;
}

int
main(int argc, char **argv)
{
	int numsSize;
	int *nums;

	while (scanf("%d", &numsSize) != EOF) {
		nums = (int *) malloc(sizeof(int) * numsSize);

		for (int i = 0; i < numsSize; i++)
		{
			if (scanf("%d", &nums[i]) == EOF) {
				printf("input error\n");
				exit(1);
			}
		}

		int max = maxSubArray(nums, numsSize);

		for (int i = 0; i < numsSize; i++)
		{
			printf("%d ", nums[i]);
		}
		printf("=> %d\n", max);
		free(nums);
	}

	return 0;
}
