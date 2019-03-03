/*************************************************************
 * Carly Tsuda
 * Software Engineering II W2019
 * Assignment 3: Unit Testing
 * This file contains functions that unit test the following 
 * eight functions in domain.c per the Assignment 3 description
 * getCost
 * getWinners
 * isGameOver
 * whoseTurn
 *
 * adventure card
 * smithy card
 * embargo card
 * cutpurse card
 *
 * **********************************************************/

#include "a3testing.h"


test_getCost()
{
    int costArray[NUM_CARDS] = {0, 2, 5, 8, 0, 3, 6, 6, 5, 4, 4, 5, 4, 4, 3, 4, 3, 5, 3, 5, 3, 4, 2, 5, 4, 4, 4};

    for(int i = curse, i <= treasure_map; i++)
    {
        if(getCost(i) == costArray[i])
            printf("%s %d %s", 'Card #', i, ': CORRECT');
        else
            printf("%s %d %s", 'Card #', i, ': INCORRECT');
    }    

    //test error states
    

    //if negative number is entered
    if(getCost(-5) == -1)
        printf("%s %d %s", 'Card #', i, ': CORRECT');
    else
        printf("%s %d %s", 'Card #', i, ': INCORRECT');
    
    //if upper bound is entered

    if(getCost(NUM_CARDS + 1) == -1)
        printf("%s %d %s", 'Card #', i, ': CORRECT');
    else
        printf("%s %d %s", 'Card #', i, ': INCORRECT');
    
}

test_getWinners()
{
}

test_isGameOver()
{
}

test_whoseTurn()
{
}

test_adventure()
{
}

test_smithy()
{
}

test_cutpurse()
{
}

test_embargo()
{
}


