/*
 * search_insert_position.c
 * 	Given a sorted array and a target value, return the index if the 
 *	target is found. If not, return the index where it would be if it
 *	were inserted in order.
 */
#include <stdio.h>
#include <stdlib.h>

#define unused(expr)    ((void) (expr))

int
searchInsert(int *nums, int numsSize, int target)
{
	for (int i = 0; i < numsSize; i++) {
		if (target <= nums[i]) {
			return i;
		}
	}
	return numsSize;
}

int
searchInsert2(int *nums, int numsSize, int target)
{
	int l = 0;
	int h = numsSize - 1;

	while (l <= h) {
		int m = (l + h) / 2;
		if (nums[m] == target) {
			return m;
		} else if (nums[m] < target) {
			l = m + 1;
		} else {
			h = m - 1;
		}
	}

	return l;
}

int
main(int argc, char **argv)
{
	int  num;
	int  target;
	int *nums;
	
	unused(argc), unused(argv);

	while (scanf("%d", &num) != EOF) {
		nums = (int *) malloc(sizeof(int) * num);
		for (int i = 0; i < num; i++) {
			if (scanf("%d", &nums[i]) == EOF) {
				printf("input error.\n");
			}
		}

		if (scanf("%d", &target) == EOF) {
			printf("get target error.\n");
		}

		int pos = searchInsert(nums, num, target);

		printf("[");
		for (int i = 0; i < num; i++) {
			printf("%d, ", nums[i]);
		}
		printf("\b\b] -> %d\n", pos);
		free(nums);
	}
	return 0;
}
