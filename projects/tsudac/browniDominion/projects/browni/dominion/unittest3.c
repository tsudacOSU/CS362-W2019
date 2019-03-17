/*****************************************************
 *Carly Tsuda
 *CS 362: Assignment 3
 * Unit Test 3
 * Due February 10, 2019
 * Unit test for fullDeckCount
 * **************************************************/

//Include statements
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	struct gameState test;
	int randomSeed = 36;
	int k [10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	initializeGame(2, k, randomSeed, &test);
	int i; //for loop index

	// test with the initial conditions

	if(fullDeckCount(0, copper, &test) == 7)
		printf("INITAL TEST, COPPER, PLAYER 1: CORRECT\n");
	else
		printf("INITIAL TEST, COPPER, PLAYER 1: INCORRECT\n");

	if(fullDeckCount(0, estate, &test) == 3)
		printf("INITAL TEST, ESTATE, PLAYER 1: CORRECT\n");
	else
		printf("INITIAL TEST, ESTATE, PLAYER 1: INCORRECT\n");

	if(fullDeckCount(1, copper, &test) == 7)
		printf("INITAL TEST, COPPER, PLAYER 2: CORRECT\n");
	else
		printf("INITIAL TEST, COPPER, PLAYER 2: INCORRECT\n");

	if(fullDeckCount(1, estate, &test) == 3)
		printf("INITAL TEST, ESTATE, PLAYER 2: CORRECT\n");
	else
		printf("INITIAL TEST, ESTATE, PLAYER 2: INCORRECT\n");

	printf("NUMBER OF SILVER, PLAYER 1 : %d = 0\n", fullDeckCount(0, silver, &test));

	printf("NUMBER OF SILVER, PLAYER 2 : %d = 0\n", fullDeckCount(1, silver, &test));

	//add silver to hand
	for(i=0; i < 5; i++)
	{
		test.handCount[0]++;
		test.hand[0][test.handCount[0]] = silver;
	}

	if(fullDeckCount(0, silver, &test) == 4)
		printf("MANUAL ADD TEST, SILVER, PLAYER 1, HAND: CORRECT\n");
	else
		printf("MANUAL ADD TEST, SILVER, PLAYER 1, HAND: INCORRECT\n");

	//add silver to discard
	
	for(i=0; i < 5; i++)
	{
		test.discardCount[0]++;
		test.discard[0][test.discardCount[0]] = silver;
	}

	if(fullDeckCount(0, silver, &test) == 8)
		printf("MANUAL ADD TEST, SILVER, PLAYER 1, HAND + DISCARD: CORRECT\n");
	else
		printf("MANUAL ADD TEST, SILVER, PLAYER 1, HAND + DISCARD: INCORRECT\n");

	//add silver to deck
	
	for(i=0; i < 5; i++)
	{
		test.deckCount[0]++;
		test.deck[0][test.deckCount[0]] = silver;
	}

	if(fullDeckCount(0, silver, &test) == 12)
		printf("MANUAL ADD TEST, SILVER, PLAYER 1, HAND + DISCARD + DECK: CORRECT\n");
	else
		printf("MANUAL ADD TEST, SILVER, PLAYER 2, HAND + DISCARD + DECK: INCORRECT\n");

	//add silver to hand
	for(i=0; i < 5; i++)
	{
		test.handCount[1]++;
		test.hand[1][test.handCount[1]] = silver;
	}

	if(fullDeckCount(1, silver, &test) == 4)
		printf("MANUAL ADD TEST, SILVER, PLAYER 2, HAND ONLY: CORRECT\n");
	else
		printf("MANUAL ADD TEST, SILVER, PLAYER 2, HAND ONLY: INCORRECT\n");
	

	test.handCount[1] -= 4;
	//add silver to discard
	
	for(i=0; i < 5; i++)
	{
		test.discardCount[1]++;
		test.discard[1][test.discardCount[1]] = silver;
	}

	if(fullDeckCount(1, silver, &test) == 4)
		printf("MANUAL ADD TEST, SILVER, PLAYER 2, DISCARD ONLY: CORRECT\n");
	else
		printf("MANUAL ADD TEST, SILVER, PLAYER 2, DISCARD ONLY: INCORRECT\n");

	test.discardCount[1] -= 4;
	
	//add silver to deck
	
	for(i=0; i < 5; i++)
	{
		test.deckCount[1]++;
		test.deck[1][test.deckCount[1]] = silver;
	}

	if(fullDeckCount(1, silver, &test) == 4)
		printf("MANUAL ADD TEST, SILVER, PLAYER 2, DECK ONLY: CORRECT\n");
	else
		printf("MANUAL ADD TEST, SILVER, PLAYER 2, DECK ONLY: INCORRECT\n");

	return 0; 
}
