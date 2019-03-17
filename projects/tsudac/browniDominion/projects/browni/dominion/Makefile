CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 


#for Assignment 3 Testing
unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c dominion.o rngs.o
	echo "Result for running unit tests:" > unittestresults.out
	echo "unittest1.c:" >> unittestresults.out

	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	./unittest1 >>unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest2.c:" >> unittestresults.out
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	./unittest2 >>unittestresults.out
	gcov dominion.c >> unittestresults.out
		
	echo "unittest3.c:" >>unittestresults.out
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	./unittest3 >>unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest4.c:" >>unittestresults.out
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)
	./unittest4 >>unittestresults.out
	gcov dominion.c >> unittestresults.out

#for Assignment 4 Testing
randomtestresults: randomtestcard1.c randomtestcard2.c randomtestadventurer.c dominion.o rngs.o
	echo "Result for running random test, card 1:">randomtestcard1.out
	
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)
	./randomtestcard1 >>randomtestcard1.out
	gcov dominion.c >>randomtestcard1.out

	echo "Result for running random test, card 2:">randomtestcard2.out
	
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)
	./randomtestcard2 >>randomtestcard2.out
	gcov dominion.c >>randomtestcard2.out
	
	#echo "Result for running random test, adventurer card:">randomtestcardadventurer.out
	
	#gcc -o randomtestcardadventurer randomtestcardadventurer.c -g dominion.o rngs.o $(CFLAGS)
	#./randomcardtestadventurer >>randomtestcardadventurer.out
	#gcov dominion.c >>randomtestcardadventurer.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
