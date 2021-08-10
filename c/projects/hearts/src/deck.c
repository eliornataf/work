#include <stdlib.h> /* malloc, free */
#include <stdio.h> /* rand */
#include <time.h> /* srand, clock */
#include "deck.h" /* Deck Header */
#include "cards.h" /* Cards Header */
#include "dynamicVector.h" /* Dynamic Vector header */

#define CARDS_ON_SUIT (13)
#define NUM_OF_SUITS (4)
#define NUM_OF_JOKERS (2)
#define WITHOUT_BLOCK_SIZE (0)

struct Deck
{
    size_t m_numOfCards;
    size_t m_numOfDecks;
    Vector_t *m_vector;
};

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static int CheckInputs(size_t _numOfDecks, int _isJokerInclude);
static int PushCardToDeck(Deck_t *_deck);
static void GetElementsData(Vector_t *_vector, size_t _firstElementIndex, int *_firstElementData, size_t _secondIndex, int *_secondIndexData);
static void SetElementsData(Vector_t *_vector, size_t _firstElementIndex, int _firstElementData, size_t _secondIndex, int _secondIndexData);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Deck_t *CreateDeck(size_t _numOfDecks, int _isJokerInclude)
{
    Deck_t *deck = NULL;

    if (FAILURE == CheckInputs(_numOfDecks, _isJokerInclude))
    {
        return NULL;
    }

    deck = (Deck_t*)malloc(sizeof(Deck_t));
    if (!deck)
    {
        return NULL;
    }

    deck->m_numOfCards = CARDS_ON_SUIT * NUM_OF_SUITS + _isJokerInclude * NUM_OF_JOKERS;
    deck->m_numOfDecks = _numOfDecks;

    deck->m_vector = VectorCreate(deck->m_numOfCards * deck->m_numOfDecks, WITHOUT_BLOCK_SIZE);
    if (!deck->m_vector)
    {
        free(deck);
        return NULL;
    }

    if (FAILURE == PushCardToDeck(deck))
    {
        VectorDestroy(deck->m_vector);
        free(deck);
        return NULL;
    }

    return deck;
}

void DestroyDeck(Deck_t *_deck)
{
    if (!_deck)
    {
        return;
    }

    VectorDestroy(_deck->m_vector);
    free(_deck);
}

int ShuffleDeck(Deck_t *_deck)
{
    int currElementData, randElementData;
    time_t currentTime;
    size_t i;

    if (!_deck) 
    {
        return FAILURE;
    }

	srand((unsigned)time(&currentTime));

    for (i = 0;i < _deck->m_numOfCards * _deck->m_numOfDecks;++i)
    {
        int randIndex = rand() % (_deck->m_numOfCards * _deck->m_numOfDecks);

        GetElementsData(_deck->m_vector, i, &currElementData, randIndex, &randElementData);
        SetElementsData(_deck->m_vector, i, randElementData, randIndex, currElementData);
    }

    return SUCCESS;
}

int DrawCardFromDeck(Deck_t *_deck)
{
    int drawCardData;

    if (!_deck) 
    {
        return DRAW_CARD_FAILED;
    }

    if (OK != VectorPop(_deck->m_vector, &drawCardData))
    {
        return DRAW_CARD_FAILED;
    }

    return drawCardData;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static int CheckInputs(size_t _numOfDecks, int _isJokerInclude)
{
    if ( (!_numOfDecks) || (0 !=_isJokerInclude && 1 != _isJokerInclude) )
    {
        return FAILURE;
    }

    return SUCCESS;
}

static int PushCardToDeck(Deck_t *_deck)
{
    size_t i, j;

    for (i = 0;i < _deck->m_numOfDecks;++i)
    {
        for (j = 0;j < _deck->m_numOfCards;++j)
        {
            if (OK != VectorPush(_deck->m_vector, j))
            {
                return FAILURE;
            }
        }
    }

    return SUCCESS;
}

static void GetElementsData(Vector_t *_vector, size_t _firstElementIndex, int *_firstElementData, size_t _secondIndex, int *_secondIndexData)
{	
	VectorGetElement(_vector, _firstElementIndex, _firstElementData);
	VectorGetElement(_vector, _secondIndex, _secondIndexData);
}

static void SetElementsData(Vector_t *_vector, size_t _firstElementIndex, int _firstElementData, size_t _secondIndex, int _secondIndexData)
{
	VectorSetElement(_vector, _firstElementIndex, _firstElementData);
	VectorSetElement(_vector, _secondIndex, _secondIndexData);
}