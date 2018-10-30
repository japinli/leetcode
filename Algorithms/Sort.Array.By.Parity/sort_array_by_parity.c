#include <stdio.h>
#include <stdlib.h>

#define UNUSED(expr)    ((void) (expr))

int *
sortArrayByParity(int *array, int size, int *rsize)
{
    int *newarray;
    int l, h;
    newarray = (int *) malloc(sizeof(int) * size);

    l = 0; h = size - 1;
    while (l <= h) {
        while (!(array[l] & 1) && l < h) {
            newarray[l] = array[l++];
        }

        while ((array[h] & 1) && l < h) {
            newarray[h] = array[h--];
        }

        newarray[l] = array[h];
        newarray[h] = array[l];

        l++, h--;
    }
    *rsize = size;
    return newarray;
}

static void
print_array(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            printf("[%d", array[i]);
        } else {
            printf(", %d", array[i]);
        }
    }
    printf("]");
}

int
main(int argc, char **argv)
{
    int size;
    int rsize;
    int *array = NULL;
    int *rarray = NULL;

    UNUSED(argc); UNUSED(argv);

    while (scanf("%d", &size) != EOF) {
        array = (int *) malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++) {
            if (scanf("%d", &array[i]) == EOF) {
                printf("input error.\n");
            }
        }

        rarray = sortArrayByParity(array, size, &rsize);

        print_array(array, size);
        printf(" => ");
        print_array(rarray, rsize);
        printf("\n");

        free(array);
        free(rarray);
    }

    return 0;
}

int *
sortArrayByParity2(int* A, int ASize, int* returnSize)
{
    int *newArray;
    int l = 0, h = ASize - 1;

    newArray = (int *) malloc(sizeof(int) * ASize);

    for (int i = 0; i < ASize; i++) {
        if (A[i] & 0x01) {
            /* even numbers */
            newArray[h--] = A[i];
        } else {
            newArray[l++] = A[i];
        }
    }

    *returnSize = ASize;
    return newArray;
}
