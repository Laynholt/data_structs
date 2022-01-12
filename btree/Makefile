.PHONY: all

all: test.out

hash.o:
	+$(MAKE) -C hash

btree.o:
	+$(MAKE) -C btree

test.o: test.c
	cc -c test.c

test.out: test.o hash.o btree.o
	cc hash/hash.o btree/btree.o test.o -o test.out

.PHONY: clean

clean:
	rm test.o hash/hash.o btree/btree.o
