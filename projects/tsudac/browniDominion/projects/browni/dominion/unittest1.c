/*****************************************************
 *Carly Tsuda
 *CS 362: Assignment 3
 * Unit Test 1
 * Due February 10, 2019
 * Unit test for getCost
 * **************************************************/

//Include statements
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//PROTOTYPE
//int test_getCost():

const int NUM_CARDS = 27;

//FUNCTION
int main()
{
	//array to store expected values of card enums in order
	int costArray[] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};
	int i; //for loop index
	//int flag = 0;
	//for loop cycles through and tests each card in order. i corresponds to card enum
	for(i= 0; i < NUM_CARDS; i++)
	{
		if(getCost(i) == costArray[i])
			printf("Card # %d TEST: CORRECT\n", i);
		else		
		{
			printf("Card # %d TEST: INCORRECT\n", i);
			//flag = 1;
		}
	}
	
	//test negative value error handling
	if(getCost(-5) == -1)
		printf("NEGATIVE TEST: CORRECT\n");
	else
	{	
		printf("NEGATIVE TEST: INCORRECT\n");
		//flag = 1;
	}
	
	//test beyond range error handling
	if(getCost(NUM_CARDS + 1) == -1)
		printf("BEYOND RANGE TEST: CORRECT\n");
	else
	{	
		printf("BEYOND RANGE TEST: INCORRECT\n");
		//flag = 1;
	}

	return 0;
}
