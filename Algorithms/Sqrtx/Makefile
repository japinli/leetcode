#
# Makefile -
#	Make sqrtx program.
#

OBJS = sqrtx.o
LIBS = -lm

program = sqrtx
testout = test.out

.PHONY: $(program)

$(program): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

.PHONY: test clean

test: $(program)
	@cat test.dat | grep -v '^#' | ./sqrtx > $(testout)
	diff -s $(testout) expected.out

clean:
	rm $(program) *.o test.out
