PROG = cgrep words btree

all:  $(PROG)

clean:
	$(RM) $(PROG)

cgrep:  CGREP.c cgrep_test.c
	$(CC) -o $@ $^

words:  WORDS.c words_test.c
	$(CC) -o $@ $^

btree: BTREE.c btree_test.c btree.h
	$(CC) -o $@ BTREE.c btree_test.c
