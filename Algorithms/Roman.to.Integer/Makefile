.PHONY: all

all: romanToInt

romanToInt: roman_to_integer.o
	gcc -o $@ $^

.PHONY: test

test: romanToInt
	@cat input.dat | ./romanToInt > test.out
	diff -s test.out expected.out

.PHONY: clean

clean:
	rm romanToInt *.o test.out

