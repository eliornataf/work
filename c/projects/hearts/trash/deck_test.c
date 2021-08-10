#include <stdio.h> /* printf */
#include "deck.h" /* Deck Header */
#include "dynamicVector.h" /* Dynamic Vector header */

#define CARDS_IN_DECK (52)
#define NUM_OF_JOKERS (2)

#define SUCCESS ("\033[1;32mSuccess\033[0m") 
#define FAILURE ("\033[1;31mFailure\033[0m") 
#define CHECK_FUNC(condition) (printf("%s\n", (condition) ? SUCCESS : FAILURE ))

void CreateDeckTest1(void)
{
    Deck_t *deck = NULL;
    size_t numOfDecks = 1;
    size_t isJokerInclude = 0;

	printf("\033[1;34m\n*******Deck Create Test 1:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    deck = CreateDeck(numOfDecks, isJokerInclude);
    
	CHECK_FUNC(NULL != deck);
	
	printf("\nExpected: SUCCESS (NULL != deck)\n");
	
	DestroyDeck(deck);
}

void CreateDeckTest2(void)
{
    Deck_t *deck = NULL;
    size_t numOfDecks = 0;
    size_t isJokerInclude = 0;

	printf("\033[1;34m\n*******Deck Create Test 2:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    deck = CreateDeck(numOfDecks, isJokerInclude);
    
	CHECK_FUNC(NULL == deck);
	
	printf("\nExpected: SUCCESS (NULL == deck)\n");
	
	DestroyDeck(deck);
}

void CreateDeckTest3(void)
{
    Deck_t *deck = NULL;
    size_t numOfDecks = 2;
    size_t isJokerInclude = 0;

	printf("\033[1;34m\n*******Deck Create Test 3:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    deck = CreateDeck(numOfDecks, isJokerInclude);
    
	CHECK_FUNC(NULL != deck);
	
	printf("\nExpected: SUCCESS (NULL != deck)\n");
	
	DestroyDeck(deck);
}

void CreateDeckTest4(void)
{
    Deck_t *deck = NULL;
    size_t numOfDecks = 1;
    size_t isJokerInclude = 3;

	printf("\033[1;34m\n*******Deck Create Test 4:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    deck = CreateDeck(numOfDecks, isJokerInclude);
    
	CHECK_FUNC(NULL == deck);
	
	printf("\nExpected: SUCCESS (NULL == deck)\n");
	
	DestroyDeck(deck);
}

void CreateDeckTest5(void)
{
    Deck_t *deck = NULL;
    size_t numOfDecks = 1;
    size_t isJokerInclude = 1;

	printf("\033[1;34m\n*******Deck Create Test 5:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    deck = CreateDeck(numOfDecks, isJokerInclude);
    
	CHECK_FUNC(NULL != deck);
	
	printf("\nExpected: SUCCESS (NULL != deck)\n");
	
	DestroyDeck(deck);
}

void ShuffleDeckTest(void)
{
    Deck_t *deck = NULL;
    size_t numOfDecks = 1;
    size_t isJokerInclude = 0;

	printf("\033[1;34m\n*******Shuffle Deck Test:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    deck = CreateDeck(numOfDecks, isJokerInclude);
    
	CHECK_FUNC(NULL != deck);
	
	printf("\nExpected: SUCCESS (NULL != deck)\n");
	
    ShuffleDeck(deck);

	DestroyDeck(deck);
}

void DrawCardFromDeckTest(void)
{
    Deck_t *deck = NULL;
    size_t numOfDecks = 1;
    size_t isJokerInclude = 0;
    size_t i;

	printf("\033[1;34m\n*******Draw Card From Deck Test:*******\n\n\033[0m");
	
    printf("Create Func Test: ");

    deck = CreateDeck(numOfDecks, isJokerInclude);
    
	CHECK_FUNC(NULL != deck);
	
	printf("\nExpected: SUCCESS (NULL != deck)\n");
	
    ShuffleDeck(deck);

    for(i = 0;i < (CARDS_IN_DECK + isJokerInclude * NUM_OF_JOKERS) * numOfDecks;++i)
    {
        DrawCardFromDeck(deck);
    }

	DestroyDeck(deck);
}


int main(void)
{
    CreateDeckTest1();
    CreateDeckTest2();
    CreateDeckTest3();
    CreateDeckTest4();
    CreateDeckTest5();

    ShuffleDeckTest();

    DrawCardFromDeckTest();

    return 0;
}