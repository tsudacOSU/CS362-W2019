/***********************************************************************
 * Random Test for Dominion Card 2 : Embargo
 * Carly Tsuda (tsudac)
 * Due March 2, 2019
 *
 **********************************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NUM_TESTS 500

//declare cutpurse here
int refacEmbargo(int cp, struct gameState *s, int hp, int cl);
void runTest(struct gameState *g);
int randomizeGameState(struct gameState *g);


int main(){
int idx;

srand(time(NULL));

struct gameState test;

for(idx = 0; idx < NUM_TESTS; idx++){
	runTest(&test);
}

return 0;
}


void runTest(struct gameState *g){
int handPos = randomizeGameState(g);
int choice1 = (rand()%20) + 6;

int beforeCoins;
int afterCoins;

int embargoTokenBefore;
int embargoTokenAfter;

beforeCoins = g->coins;
embargoTokenBefore = g->embargoTokens[choice1];

refacEmbargo(g->whoseTurn, g, handPos, choice1);

afterCoins = g->coins;
embargoTokenAfter = g->embargoTokens[choice1];

if(beforeCoins == afterCoins -2){
	printf("Coin Count CORRECT\n");
}

else{
	printf("Coin Count INCORRECT\n");
}

if(embargoTokenBefore == embargoTokenAfter -1){
	printf("Embargo Token CORRECT\n");
}

else{
	printf("Embargo Token INCORRECT\n");
}

}


/*************************************************************
 *                       RandomizeGameState
 * Randomizes the game state parameters relevant to the Cutpurse
 * card
 ***********************************************************/
int randomizeGameState(struct gameState *g){

int k[10];
int i;
int j;
int temp;
int numPlayers = (rand()%2) + 2;
int randomseed = 40;
int handPosition = rand()%5;


//randomize array of kingdom cards
k[0] = embargo;

for(i = 1; i < 10; i++){
	temp = (rand()% 20) + 6; 
	k[i] = temp;
	for(j = 0; j < i; j++){
		if(temp == k[j]){
			i--;
		}	
	}
}

initializeGame(numPlayers, k, randomseed, g);

//randomize cutpurse variables
// current player

g->whoseTurn = rand()%numPlayers;

// hand position
g->hand[g->whoseTurn][handPosition] = rand()%5;


return handPosition;

}
