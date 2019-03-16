CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: 
	gcc -o testme testme.c -g  $(CFLAGS)
	./testme
# add in gcov

all: testme

clean: 
	rm -f testme *.gcov *.gcda *.gcno
