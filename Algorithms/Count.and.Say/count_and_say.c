/*
 * count_and_say.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xstring_t
{
	size_t capacity;
	size_t length;
	char   data[1];
} xstring_t;

typedef xstring_t *xstring;

xstring
xstring_new(size_t size)
{
	xstring res = (xstring) malloc(sizeof(xstring_t) + size + 1);
	res->capacity = size;
	res->length = 0;
	res->data[res->length] = '\0';
	return res;
}

xstring
xstring_init(const char *str)
{
	size_t  len = strlen(str);
	xstring res = xstring_new(len);

	memcpy(res->data, str, len);
	
	return res;
}

void
xstring_clear(xstring str)
{
	str->length = 0;
	str->data[str->length] = '\0';
}

xstring
xstring_append_char(xstring str, char ch)
{
	
	if (str->length >= str->capacity) {
		size_t sz = 2 * str->capacity;
		str = (xstring) realloc(str, sizeof(xstring_t) + sz + 1);
		str->capacity = sz;
	}

	str->data[str->length++] = ch;
	str->data[str->length] = '\0';

	return str;
}

xstring
xstring_append_int(xstring str, int val)
{
	char    buf[10];
	snprintf(buf, 10, "%d", val);

	for (int i = 0; buf[i]; i++) {
		str = xstring_append_char(str, buf[i]);
	}

	return str;
}

#define unused(expr)    ((void) (expr))

char *
countAndSay(int n)
{
	if (n == 0) {
		return "";
	} else if (n == 1) {
		return "1";
	}

	xstring tmp = xstring_new(10);
	xstring ref = xstring_init("1");

	while (n-- > 1) {
		int  cnt = 1;
		char val = ref->data[0];
		for (int i = 1; i < ref->length; i++) {
			if (val == ref->data[i]) {
				cnt++;
			} else {
				tmp = xstring_append_int(tmp, cnt);
				tmp = xstring_append_char(tmp, val);
				val = ref->data[i];
				cnt = 1;
			}
		}
		
		tmp = xstring_append_int(tmp, cnt);
		tmp = xstring_append_char(tmp, val);

		xstring t = ref;
		ref = tmp;
		tmp = t;
		xstring_clear(tmp);
	}	

	return ref->data;
}
		
int
main(int argc, char **argv)
{
	int nth;
	
	unused(argc), unused(argv);

	while (scanf("%d", &nth) != EOF) {
		printf("\"%s\"\n", countAndSay(nth));
	}

	return 0;
}
