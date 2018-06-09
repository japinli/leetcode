#
# Makefile -
#	Make count_and_say program.
#

OBJS = count_and_say.o

program = count_and_say
testout = test.out

.PHONY: $(program)

$(program): $(OBJS)
	$(CC) -o $@ $^

.PHONY: test clean

test: $(program)
	@cat test.dat | grep -v '^#' | ./count_and_say > $(testout)
	diff -s $(testout) expected.out

clean:
	rm $(program) *.o test.out
