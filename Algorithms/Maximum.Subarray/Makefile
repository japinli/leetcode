#
# Makefile -
# 	Make maximum_subarray program.
#

OBJS = maximum_subarray.o

program = maximum_subarray
testout = test.out

.PHONY: all

all: $(program)

$(program): $(OBJS)
	$(CC) -o $@ $^

.PHONY: test clean

test: $(program)
	@cat test.dat | grep -v '^#' | ./maximum_subarray > $(testout)
	diff -s $(testout) expected.out

clean:
	rm $(program) *.o test.out
