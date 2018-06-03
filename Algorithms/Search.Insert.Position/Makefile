#
# Makefile -
# 	Make search_insert_position program.
#

OBJS = search_insert_position.o

program = search_insert_position
testout = test.out

.PHONY: all

all: $(program)

$(program): $(OBJS)
	$(CC) -o $@ $^

.PHONY: test clean

test: $(program)
	@cat test.dat | grep -v '^#' | ./search_insert_position > $(testout)
	diff -s $(testout) expected.out

clean:
	rm $(program) *.o test.out
