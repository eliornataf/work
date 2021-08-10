#include <stdio.h> /* printf */
#include "player.h" /* Player Header */

#define NUM_OF_SUITS (4)
#define CARDS_IN_SUIT (13)
#define CARDS_IN_DECK (52)
#define NUM_OF_JOKERS (2)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void CreatePlayerTest1(void)
{
    Player_t *player = NULL;
    char *playerName = "Elior";
    int isHuman = 0;
    size_t numOfDecks = 1;
    int isJokerInclude = 0;

	printf("\033[1;34m\n*******Player Create Test 1:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    player = CreatePlayer(playerName, isHuman, numOfDecks, isJokerInclude);
    
	CHECK_FUNC(NULL != player);
	
	printf("\nExpected: SUCCESS (NULL != player)\n");
	
	DestroyPlayer(player);
}

void CreatePlayerTest2(void)
{
    Player_t *player = NULL;
    char *playerName = NULL;
    int isHuman = 0;
    size_t numOfDecks = 1;
    int isJokerInclude = 0;

	printf("\033[1;34m\n*******Player Create Test 2:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    player = CreatePlayer(playerName, isHuman, numOfDecks, isJokerInclude);
    
	CHECK_FUNC(NULL == player);
	
	printf("\nExpected: SUCCESS (NULL == player)\n");
	
	DestroyPlayer(player);
}

void CreatePlayerTest3(void)
{
    Player_t *player = NULL;
    char *playerName = "Hadar";
    int isHuman = 2;
    size_t numOfDecks = 1;
    int isJokerInclude = 0;

	printf("\033[1;34m\n*******Player Create Test 3:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    player = CreatePlayer(playerName, isHuman, numOfDecks, isJokerInclude);
    
	CHECK_FUNC(NULL == player);
	
	printf("\nExpected: SUCCESS (NULL == player)\n");
	
	DestroyPlayer(player);
}

void CreatePlayerTest4(void)
{
    Player_t *player = NULL;
    char *playerName = "Hadar";
    int isHuman = 0;
    size_t numOfDecks = 0;
    int isJokerInclude = 0;

	printf("\033[1;34m\n*******Player Create Test 4:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    player = CreatePlayer(playerName, isHuman, numOfDecks, isJokerInclude);
    
	CHECK_FUNC(NULL == player);
	
	printf("\nExpected: SUCCESS (NULL == player)\n");
	
	DestroyPlayer(player);
}

void CreatePlayerTest5(void)
{
    Player_t *player = NULL;
    char *playerName = "Hadar";
    int isHuman = 0;
    size_t numOfDecks = 1;
    int isJokerInclude = 2;

	printf("\033[1;34m\n*******Player Create Test 5:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    player = CreatePlayer(playerName, isHuman, numOfDecks, isJokerInclude);
    
	CHECK_FUNC(NULL == player);
	
	printf("\nExpected: SUCCESS (NULL == player)\n");
	
	DestroyPlayer(player);
}

void PlayerTakeCardTest1(void)
{
    Player_t *player = NULL;
    char *playerName = "Hadar";
    int isHuman = 1;
    size_t numOfDecks = 1;
    int isJokerInclude = 0;
    ADTError_t status;
    size_t i;

	printf("\033[1;34m\n*******Player Take Card Test 1:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    player = CreatePlayer(playerName, isHuman, numOfDecks, isJokerInclude);
    
	CHECK_FUNC(NULL != player);
	
	printf("\nExpected: SUCCESS (NULL == player)\n");

    for(i = 0;i < CARDS_IN_DECK;++i)
    {   
        printf("Player Take Card Func Test %ld: ", i);

         status = PlayerTakeCard(player, i);
            
        CHECK_FUNC(OK == status);
    }

    printf("\nExpected: 52 SUCCESS (status check)\n");

	DestroyPlayer(player);
}

void PlayerTakeCardTest2(void)
{
    Player_t *player = NULL;
    ADTError_t status;
    size_t i;

	printf("\033[1;34m\n*******Player Take Card Test 1:*******\n\n\033[0m");
	
    for (i = 0;i < CARDS_IN_DECK;++i)
    {   
        printf("Player Take Card Func Test %ld: ", i);

         status = PlayerTakeCard(player, i);
            
        CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
    }

    printf("\nExpected: 52 SUCCESS (status check)\n");

	DestroyPlayer(player);
}

void SortPlayerCardsByRankTest1(void)
{
    Player_t *player = NULL;
    char *playerName = "Hadar";
    int isHuman = 1;
    size_t numOfDecks = 1;
    int isJokerInclude = 0;
    ADTError_t status;
    int i;

	printf("\033[1;34m\n*******Sort Player Cards By Rank Test 1:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    player = CreatePlayer(playerName, isHuman, numOfDecks, isJokerInclude);
    
	CHECK_FUNC(NULL != player);
	
	printf("\nExpected: SUCCESS (NULL == player)\n");
	
    for (i = CARDS_IN_DECK - 1;0 <= i;--i)
    {   
        printf("Player Take Card Func Test %d: ", i);

         status = PlayerTakeCard(player, i);
            
        CHECK_FUNC(OK == status);
    }

    printf("\nExpected: 52 SUCCESS (status check)\n");

    status = SortPlayerCardsByRank(player);

    printf("\nSort Player Cards By Rank Func Test: ");

    CHECK_FUNC(OK == status);

    printf("\nExpected: 1 SUCCESS (status check)\n");

	DestroyPlayer(player);
}

void SortPlayerCardsByRankTest2(void)
{
    Player_t *player = NULL;
    ADTError_t status;
    int i;

	printf("\033[1;34m\n*******Sort Player Cards By Rank Test 2:*******\n\n\033[0m");
	
    for (i = CARDS_IN_DECK - 1;0 <= i;--i)
    {   
        printf("Player Take Card And Put In Suit Vec Func Test %d: ", i);

         status = PlayerTakeCard(player, i);
            
        CHECK_FUNC(POINTER_NOT_INITIALIZE == status);
    }

    printf("\nExpected: 52 SUCCESS (status check)\n");

    status = SortPlayerCardsByRank(player);

    printf("\nSort Player Cards By Rank Func Test: ");

    CHECK_FUNC(POINTER_NOT_INITIALIZE == status);

    printf("\nExpected: 1 SUCCESS (status check)\n");

	DestroyPlayer(player);
}


int main(void)
{
    CreatePlayerTest1();
    CreatePlayerTest2();
    CreatePlayerTest3();
    CreatePlayerTest4();
    CreatePlayerTest5();

    PlayerTakeCardTest1();
    PlayerTakeCardTest2();

    SortPlayerCardsByRankTest1();
    SortPlayerCardsByRankTest2();

    return 0;
}