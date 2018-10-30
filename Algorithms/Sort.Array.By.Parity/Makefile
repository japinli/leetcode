#
# Makefile -
# 	Make search_insert_position program.
#

OBJS = sort_array_by_parity.o

program = sort_array_by_parity
testout = test.out

.PHONY: all

all: $(program)

$(program): $(OBJS)
	$(CC) -o $@ $^

.PHONY: test clean

test: $(program)
	@cat test.dat | grep -v '^#' | ./sort_array_by_parity > $(testout)
	diff -s $(testout) expected.out

clean:
	rm $(program) *.o test.out
