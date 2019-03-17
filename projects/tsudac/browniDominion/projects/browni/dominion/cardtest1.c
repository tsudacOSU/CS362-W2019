/*****************************************************
 *Carly Tsuda
 *CS 362: Assignment 3
 * Unit Test 5, Card Test 1
 * Due February 10, 2019
 * Card test for smithy
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
	int beforeHandCount;

	initializeGame(2, k, randomSeed, &test);
	 
	
	
	return 0;
}
