/*****************************************************
 *Carly Tsuda
 *CS 362: Assignment 3
 * Unit Test 4
 * Due February 10, 2019
 * Unit test for whoseTurn
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
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};	


	initializeGame(2, k, randomSeed, &test);

	if(whoseTurn(&test) == 0)
		printf("INITIAL TEST: CORRECT\n");
	else
		printf("INTIAL TEST: INCORRECT\n");
	
	test.whoseTurn = 1;


	if(whoseTurn(&test) == 1)
		printf("MANUAL TEST: CORRECT\n");
	else
		printf("MANUAL TEST: INCORRECT\n");

	test.whoseTurn = -3;
	
	if(whoseTurn(&test) == -3)
		printf("UNDER RANGE TEST: CORRECT\n");
	else
		printf("UNDER RANGE TEST: INCORRECT\n");
	
	test.whoseTurn = 8;

	if(whoseTurn(&test) == 8)
		printf("OVER RANGE TEST: CORRECT\n");
	else
		printf("OVER RANGE TEST: INCORRECT\n");
	

}
