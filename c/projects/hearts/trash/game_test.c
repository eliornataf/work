#include <stdio.h> /* printf */
#include "game.h" /* Game Header */

#define NUM_OF_SUITS (4)
#define CARDS_IN_SUIT (13)
#define CARDS_IN_DECK (52)
#define NUM_OF_JOKERS (2)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void CreateGameTest1(void)
{
    Game_t *game = NULL;
    size_t numOfPlayers = 4;
    size_t numOfDecks = 1;
    size_t isJokerInclude = 0;
    size_t scoreToEnd = 100;
    size_t numOfHumanPlayers = 2;

    printf("\033[1;34m\n*******Player Create Test 1:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    game = CreateGame(numOfPlayers, numOfDecks, isJokerInclude, scoreToEnd, numOfHumanPlayers);
    
    CHECK_FUNC(NULL != game);
	
	printf("\nExpected: SUCCESS (NULL != game)\n");
	
	DestroyGame(game);
}

void CreateGameTest2(void)
{
    Game_t *game = NULL;
    size_t numOfPlayers = 1;
    size_t numOfDecks = 1;
    size_t isJokerInclude = 0;
    size_t scoreToEnd = 100;
    size_t numOfHumanPlayers = 2;

    printf("\033[1;34m\n*******Player Create Test 2:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    game = CreateGame(numOfPlayers, numOfDecks, isJokerInclude, scoreToEnd, numOfHumanPlayers);
    
    CHECK_FUNC(NULL == game);
	
	printf("\nExpected: SUCCESS (NULL == game)\n");
	
	DestroyGame(game);
}

void CreateGameTest3(void)
{
    Game_t *game = NULL;
    size_t numOfPlayers = 0;
    size_t numOfDecks = 1;
    size_t isJokerInclude = 0;
    size_t scoreToEnd = 100;
    size_t numOfHumanPlayers = 2;

    printf("\033[1;34m\n*******Player Create Test 3:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    game = CreateGame(numOfPlayers, numOfDecks, isJokerInclude, scoreToEnd, numOfHumanPlayers);
    
    CHECK_FUNC(NULL == game);
	
	printf("\nExpected: SUCCESS (NULL == game)\n");
	
	DestroyGame(game);
}

void CreateGameTest4(void)
{
    Game_t *game = NULL;
    size_t numOfPlayers = 2;
    size_t numOfDecks = 0;
    size_t isJokerInclude = 0;
    size_t scoreToEnd = 100;
    size_t numOfHumanPlayers = 2;

    printf("\033[1;34m\n*******Player Create Test 4:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    game = CreateGame(numOfPlayers, numOfDecks, isJokerInclude, scoreToEnd, numOfHumanPlayers);
    
    CHECK_FUNC(NULL == game);
	
	printf("\nExpected: SUCCESS (NULL == game)\n");
	
	DestroyGame(game);
}

void CreateGameTest5(void)
{
    Game_t *game = NULL;
    size_t numOfPlayers = 2;
    size_t numOfDecks = 1;
    size_t isJokerInclude = 3;
    size_t scoreToEnd = 100;
    size_t numOfHumanPlayers = 2;

    printf("\033[1;34m\n*******Player Create Test 5:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    game = CreateGame(numOfPlayers, numOfDecks, isJokerInclude, scoreToEnd, numOfHumanPlayers);
    
    CHECK_FUNC(NULL == game);
	
	printf("\nExpected: SUCCESS (NULL == game)\n");
	
	DestroyGame(game);
}

void CreateGameTest6(void)
{
    Game_t *game = NULL;
    size_t numOfPlayers = 2;
    size_t numOfDecks = 1;
    size_t isJokerInclude = 0;
    size_t scoreToEnd = 0;
    size_t numOfHumanPlayers = 2;

    printf("\033[1;34m\n*******Player Create Test 6:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    game = CreateGame(numOfPlayers, numOfDecks, isJokerInclude, scoreToEnd, numOfHumanPlayers);
    
    CHECK_FUNC(NULL == game);
	
	printf("\nExpected: SUCCESS (NULL == game)\n");
	
	DestroyGame(game);
}





int main(void)
{
    CreateGameTest1();
    CreateGameTest2();
    CreateGameTest3();
    CreateGameTest4();
    CreateGameTest5();
    CreateGameTest6();

    return 0;
}