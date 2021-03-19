/*----------------------------------------------------------------------------
 *
 * fizz_buzz.c
 *   Write a program that outputs the string representation of numbers from
 *   `1` to `n`.
 *
 *   But for multiples of three it should output “Fizz” instead of the
 *   number and for the multiples of five output “Buzz”. For numbers which
 *   are multiples of both three and five output “FizzBuzz”.
 *
 *----------------------------------------------------------------------------
 */

#if 0

char ** 
fizzBuzz(int n, int *returnSize)
{
    char **res = (char *) malloc(sizeof(char *) * n);
    char tmp[16];
    *returnSize = n;

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            snprintf(tmp, sizeof(tmp), "%s", "FizzBuzz");
        } else if (i % 3 == 0) {
            snprintf(tmp, sizeof(tmp), "%s", "Fizz");
        } else if (i % 5 == 0) {
            snprintf(tmp, sizeof(tmp), "%s", "Buzz");
        } else {
            snprintf(tmp, sizeof(tmp), "%d", i);
        }
        res[i - 1] = strdup(tmp);
    }

    return res;
}

#endif

struct fizz_t
{
    int   key;
    char *val;
};

char ** 
fizzBuzz(int n, int *returnSize)
{
    char **res = (char *) malloc(sizeof(char *) * n);
    struct fizz_t fizz_buzz[] = {
        {3, "Fizz"},
        {5, "Buzz"},
        {0, NULL}
    };
    
    for (int i = 1; i <= n; i++) {
        char tmp[16] = { 0 };
        for (struct fizz_t *j = &fizz_buzz; j->val != NULL; j++) {
            if (i % j->key == 0) {
                snprintf(tmp + strlen(tmp), sizeof(tmp) - strlen(tmp), "%s", j->val);
            }
        }
        if (tmp[0] == '\0') {
            snprintf(tmp, sizeof(tmp), "%d", i);
        }
        res[i - 1] = strdup(tmp);
    }
    
    *returnSize = n;
    return res;
}