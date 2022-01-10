all: test.out

hash.o:
	+$(MAKE) -C hash

tree.o:
	+$(MAKE) -C tree

test.o: test.c
	cc -c test.c

test.out: test.o hash.o tree.o
	cc hash/hash.o tree/tree.o test.o -o test.out
