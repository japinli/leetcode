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

/*
 * Another method.
 */
static int
toNumber(char ch)
{
    switch (ch) {
    case 'I': return 1;
    case 'V': return 5;
    case 'X': return 10;
    case 'L': return 50;
    case 'C': return 100;
    case 'D': return 500;
    case 'M': return 1000;
    }

    return 0;
}

static int
romanToInt2(char *s)
{
    int result = toNumber(s[0]);
    int first, last;

    for (int i = 1; s[i] != 0; i++) {
        first = toNumber(s[i - 1]);
        last = toNumber(s[i]);
        if (first < last) {
            result += last - 2 * first;
        } else {
            result += last;
        }
    }

    return result;
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
