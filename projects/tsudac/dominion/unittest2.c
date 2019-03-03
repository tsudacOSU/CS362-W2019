/*****************************************************
 *Carly Tsuda
 *CS 362: Assignment 3
 * Unit Test 2
 * Due February 10, 2019
 * Unit test for isGameOver
 * **************************************************/

//Include statements
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//PROTOTYPE


//FUNCTION
int main()
{
	
	int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
	int randomSeed= 36;
	//test structs
	struct gameState over;  
	struct gameState not_over;
	struct gameState error;

	//test case where both game over conditions are true
	initializeGame(2, k, randomSeed, &over);

	//test when game is not over
	if(isGameOver(&over) == 1)
		printf("TEST CASE 1: INCORRECT\n");
	else
		printf("TEST CASE 1: CORRECT\n");

	//test when no province cards are left
	over.supplyCount[province] = 0;
	
	
	if(isGameOver(&over) == 1)
		printf("TEST CASE 2 - EMPTY PROVINCE PILE CONDITION: CORRECT\n");
	else
		printf("TEST CASE 2 - EMPTY PROVINCE PILE CONDITION: INCORRECT\n");

	//test when three supply piles are empty
	over.supplyCount[province] = 5;
	over.supplyCount[estate] = 0; 
	over.supplyCount[silver] = 0;
	over.supplyCount[gardens] = 0; 
	

	if(isGameOver(&over) == 1)
		printf("TEST CASE 3 - THREE SUPPLY PILES EMPTY CONDITION: CORRECT\n");
	else
		printf("TEST CASE 3 - THREE SUPPLY PILES EMPTY CONDITION: INCORRECT\n");
	
	//test upper edge - both cases
	over.supplyCount[estate] = 5;
	over.supplyCount[sea_hag] = 0;
 
	if(isGameOver(&over) == 1)
		printf("TEST CASE 4 - UPPER EDGE OVER: CORRECT\n");
	else
		printf("TEST CASE 4 - UPPER EDGE OVER: INCORRECT\n");

	over.supplyCount[sea_hag] = 5;

	
	if(isGameOver(&over) == 0)
		printf("TEST CASE 5 - UPPER EDGE NOT OVER: CORRECT\n");
	else
		printf("TEST CASE 5 - UPPER EDGE NOT OVER: INCORRECT\n");

	

	return 0;



}
