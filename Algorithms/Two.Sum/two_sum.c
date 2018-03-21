/*----------------------------------------------------------------------------
 *
 * Two sum
 *
 * gcc -o two_sum two_sum.c
 *
 *----------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>

#define unused(expr) ((void) (expr))

typedef struct num_idx_s
{
    int idx;
    int num;
} num_idx;

static int
compare(const void *a, const void *b)
{
    return ((num_idx *) a)->num - ((num_idx *) b)->num;
}


int *
twoSum(int *nums, int numSize, int target)
{
    int *result = (int *) malloc(sizeof(int) * 2);
    num_idx *tmp = (num_idx *) malloc(sizeof(num_idx) * numSize);

    for (int i = 0; i < numSize; i++) {
        tmp[i].idx = i;
        tmp[i].num = nums[i];
    }

    qsort(tmp, numSize, sizeof(num_idx), compare);

    int i = 0, j = numSize - 1;

    while (i < j) {
        int now = tmp[i].num + tmp[j].num;
        if (now == target) {
            result[0] = tmp[i].idx;
            result[1] = tmp[j].idx;

            break;
        } else if (now < target) {
            i++;
        } else {
            j--;
        }
    }

    free(tmp);
    return result;
}

int
main(int argc, char *argv[])
{
    int numSize, target;
    int *nums, *result;

    unused(argc), unused(argv);

    while (scanf("%d%d", &numSize, &target) != EOF) {
        nums = (int *) malloc(sizeof(int) * numSize);
        for (int i = 0; i < numSize; ++i) {
            if (scanf("%d", &nums[i]) == EOF) {
                fprintf(stderr, "ERROR: input data does not match.");
                free(nums);
                return 1;
            }
        }

        result = twoSum(nums, numSize, target);

        printf("[");
        for (int i = 0; i < numSize - 1; i++) {
            printf("%d, ", nums[i]);
        }
        printf("%d] --> [%d, %d]\n", nums[numSize - 1], result[0], result[1]);

        free(result);
        free(nums);
    }
    return 0;
}
