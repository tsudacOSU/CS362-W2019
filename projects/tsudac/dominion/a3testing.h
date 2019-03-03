/*********************************************************************
 * Carly Tsuda
 * CS 362 Software Engineering II W2019
 * Assignment 3: Unit Testing
 * This is the header file for the Unit Tests for Assignment 3. I 
 * tested the following functions:
 * getCost
 * getWinners
 * isGameOver
 * whoseTurn
 *
 * adventure card
 * smithy card
 * embargo card
 * cutpurse card
 * *****************************************************************/
#ifndef _A3TESTING_H
#define _A3TESTING_H

// Include statements
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NUM_CARDS 26

test_getCost();
test_getWinners();
test_isGameOver();
test_whoseTurn();
test_adventure();
test_smithy();
test_cutpurse();
test_embargo();


#endif
