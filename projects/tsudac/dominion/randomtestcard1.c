/***********************************************************************
 * Random Test for Dominion Card 1 : Cutpurse
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
int refacCutpurse(int cp, struct gameState *s, int hp);
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
int i; //idx
int playersCopperBefore[g->numPlayers];
int playersCopperAfter[g->numPlayers];
int j;
int handPos = randomizeGameState(g);

//store number of coppers in each player's hand before running test

for(i = 0; i < g->numPlayers; i++){
	if(i != g->whoseTurn){
		for (j = 0; j < g->handCount[i]; j++){
			if(g->hand[i][j] == copper){
				playersCopperBefore[i]++;
			}
		}
	}
}


refacCutpurse(g->whoseTurn, g, handPos);

//store number of coppers in each player's hand after running test
for(i = 0; i < g->numPlayers; i++){
	if(i != g->whoseTurn){
		for (j = 0; j < g->handCount[i]; j++){
			if(g->hand[i][j] == copper){
				playersCopperAfter[i]++;
			}
		}
	}
}


for(i = 0; i < g->numPlayers; i++){
	if(i != g->whoseTurn && playersCopperBefore[i] > 1){
		if(playersCopperBefore[i] == 0){
			printf("Player %d revealed hand?\n", i);
		}
		if(playersCopperBefore[i] == playersCopperAfter[i] + 2){
			printf("Player %d Copper Count CORRECT\n", i);
		}
		else{
			printf("Player %d Copper Count INCORRECT\n", i);
		}
	}
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
k[0] = cutpurse;

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
g->hand[g->whoseTurn][handPosition] = cutpurse;

// coppers in players' hands
for(i = 0; i < g->numPlayers; i++){
int totalCoppers = rand()%5;

	if(i != g->whoseTurn){
		for(j=0; j< g->handCount[i]; j++){
			if(totalCoppers > 0){
				g->hand[i][j] = copper;
				totalCoppers--;
			}
		
			else{
				temp = rand()%26;
			}
	 	}
	}
	
}

return handPosition;

}
