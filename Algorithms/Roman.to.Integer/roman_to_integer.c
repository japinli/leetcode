/*
 * roman_to_integer.c
 *     Given a roman numeral, convert it to an integer.
 */
#include <stdio.h>

#define unused(expr)    ((void) (expr))

static int
romanToInt(char *s)
{
    int sum = 0;

    while (*s) {
        switch (*s++) {
	case 'I':
            if (*s == 'V' || *s == 'X') {
                sum += (*s == 'V' ? 4 : 9);
                s++;
            } else {
                sum += 1;
            }
	    break;
	case 'V':
            sum += 5;
            break;
	case 'X':
            if (*s == 'L' || *s == 'C') {
                sum += (*s == 'L' ? 40 : 90);
                s++;
            } else {
                sum += 10;
            }
            break;
	case 'L':
            sum += 50;
            break;
	case 'C':
            if (*s == 'D' || *s == 'M') {
                sum += (*s == 'D' ? 400 : 900);
                s++;
            } else {
                sum += 100;
            }
            break;
	case 'D':
            sum += 500;
            break;
	case 'M':
            sum += 1000;
            break;
	}
    }

    return sum;
}

int
main(int argc, char **argv)
{
    char roman_numeral[100];
    
    unused(argc), unused(argv);

    while (scanf("%s", roman_numeral) != EOF) {
        int integer = romanToInt(roman_numeral);
        printf("%s -> %d\n", roman_numeral, integer);
    }

    return 0;
}
