/*----------------------------------------------------------------------------
 *
 * sqrtx.c
 *
 * gcc -o sqrtx sqrtx.c -lm
 *
 *----------------------------------------------------------------------------
 */
#include <stdio.h>
#include <math.h>

#define UNUSED(expr)    ((void) (expr))

int
mySqrt(int x)
{
	return sqrt((double) x);
}

int
mySqrt1(int x)
{
	long i = 1;

	while (i * i <= x)
	{
		i++;
	}

	return i - 1;
}

/*
 * Newton's method
 */
int
mySqrt2(int x)
{
	long r = x;

	while (r * r > x)
	{
		r = (r + x / r) / 2;
	}

	return r;
}

int
main(int argc, char **argv)
{
	int x;

	UNUSED(argc);
	UNUSED(argv);

	while (scanf("%d", &x) != EOF) {
		printf("sqrt(%d) = %d\n", x, mySqrt1(x));
	}

	return 0;
}
