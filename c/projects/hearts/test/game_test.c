#include <stdio.h> /* printf */
#include "game.h" /* Game Header */

#define NUM_OF_SUITS (4)
#define CARDS_IN_SUIT (13)
#define CARDS_IN_DECK (52)
#define NUM_OF_JOKERS (2)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void RunGameTest(void)
{
    Game_t *game = NULL;
    size_t numOfPlayers = 4;
    size_t numOfDecks = 1;
    size_t isJokerInclude = 0;
    size_t scoreToEnd = 100;
    size_t numOfHumanPlayers = 0;
	
    printf("Create Func Test: ");

    game = CreateGame(numOfPlayers, numOfDecks, isJokerInclude, scoreToEnd, numOfHumanPlayers);
    
    CHECK_FUNC(NULL != game);
	
	printf("\nExpected: SUCCESS (NULL != game)\n");

    printf("Run Game Func Test: ");
	
    RunGame(game);
}

int main(void)
{
    RunGameTest();

    return 0;
}
