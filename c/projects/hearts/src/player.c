#include <stdlib.h> /* malloc, free */
#include <string.h> /* strcpy */
#include "player.h" /* Player Header */
#include "dynamicVector.h" /* Dynamic Vector header */
#include "sort.h" /* Sort Header */
#include "cards.h" /* Cards Header */
#include "UI.h" /* UI Header */

#define STR_LENGTH (100)
#define WITHOUT_BLOCK_SIZE (0)
#define CARDS_ON_SUIT (13)
#define NUM_OF_SUITS (4)
#define NUM_OF_JOKERS (2)
#define POP_DATA_ERROR (-2)
#define IS_NOT_HUMAN (0)
#define IS_HUMAN (1)

/*****************************************/

size_t g_playerNum = 0; 

/*****************************************/

struct Player
{
    char *m_playerName;
    size_t m_playerNum;
    int m_isHuman;
    size_t m_numOfDecks;
    int m_isJokerInclude;
    Vector_t **m_arrOfVectors;
};

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static int CheckInputs(char *_playerName, int _isHuman, size_t _numOfDecks, int _isJokerInclude);
static int AllocVectors(Player_t *_player);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Player_t *CreatePlayer(char *_playerName, int _isHuman, size_t _numOfDecks, int _isJokerInclude)
{
    Player_t *player = NULL;
    
    if (FAILURE == CheckInputs(_playerName, _isHuman, _numOfDecks, _isJokerInclude))
    {
        return NULL;
    }
    
    player = (Player_t*)malloc(sizeof(Player_t));
    if (!player)
    {
        return NULL;
    }

    player->m_playerName = (char*)malloc(STR_LENGTH * sizeof(char));
    if (!player->m_playerName)
    {
        free(player);
        return NULL;
    }

    strcpy(player->m_playerName, _playerName);

    player->m_playerNum = g_playerNum++;
    player->m_isHuman = _isHuman;
    player->m_numOfDecks = _numOfDecks;
    player->m_isJokerInclude = _isJokerInclude;

    player->m_arrOfVectors = (Vector_t**)malloc( (NUM_OF_SUITS + _isJokerInclude) * sizeof(Vector_t*));
    if (!player->m_arrOfVectors)
    {
        free(player->m_playerName);
        free(player);
        return NULL;
    }

    if (FAILURE == AllocVectors(player))
    {
        free(player->m_arrOfVectors);
        free(player->m_playerName);
        free(player);
        return NULL;
    }

    return player;
}

void DestroyPlayer(Player_t *_player)
{
    size_t i;

    if (!_player)
    {
        return;
    }

    for (i = 0;i < NUM_OF_SUITS + _player->m_isJokerInclude;++i)
    {
        VectorDestroy(_player->m_arrOfVectors[i]);
    }

    free(_player->m_arrOfVectors);
    free(_player->m_playerName);
    free(_player);
}

int PlayerIsHuman(Player_t *_player)
{
    if (!_player)
    {
        return IS_NOT_HUMAN;
    }

    return _player->m_isHuman;
}

int PlayerGetCard(Player_t *_player, int _cardData)
{
    CardSuit_t foundSuit;
    
    if (!_player)
    {
        return FAILURE;
    }

    foundSuit = FindCardSuit(_cardData);
    if (SUIT_ERROR == foundSuit)
    {
        return FAILURE;
    }

    if (OK != VectorPush(_player->m_arrOfVectors[foundSuit], _cardData))
    {
        return FAILURE;
    }

    return SUCCESS;
}

int SortPlayerCardsByRank(Player_t *_player)
{
    size_t i;

    if (!_player)
    {
        return FAILURE;
    }

    for (i = 0;i < NUM_OF_SUITS + (size_t)_player->m_isJokerInclude;++i)
    {
        if (OK != BubbleSort(_player->m_arrOfVectors[i]))
        {
            return FAILURE;
        }
    }

    return SUCCESS;
}

int PlayerSearchCardByIndex(Player_t *_player, int _searchCardData)
{
    CardSuit_t foundSuit;
    int getElementData;
    size_t vecNumOfElements, i;

    if (!_player)
    {
        return IS_NOT_FOUND;
    }

    foundSuit = FindCardSuit(_searchCardData);
    if (SUIT_ERROR == foundSuit)
    {
        return IS_NOT_FOUND;
    }

    VectorNumOfElements(_player->m_arrOfVectors[foundSuit], &vecNumOfElements);

    for (i = 0;i < vecNumOfElements;++i)
    {
        VectorGetElement(_player->m_arrOfVectors[foundSuit], i, &getElementData);
        if (_searchCardData == getElementData)
        {
            return IS_FOUND;
        }
    }

    return IS_NOT_FOUND;
}

int PlayerGiveCard(Player_t *_player, int _cardData, int *_isHeartCardPresented, size_t _numOfTrick, Strategy_t _strategyFunc)
{
    CardSuit_t cardSuit;
    int givenCardData;

    if (!_player)
    {
        return ERROR_GIVE_CARD;
    }

    cardSuit = FindCardSuit(_cardData);

    givenCardData = (*_strategyFunc)(_player->m_arrOfVectors, cardSuit, _isHeartCardPresented, _numOfTrick);

    if (POP_DATA_ERROR == givenCardData)
    {
        return ERROR_GIVE_CARD;
    }

    return givenCardData;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static int CheckInputs(char *_playerName, int _isHuman, size_t _numOfDecks, int _isJokerInclude)
{
    if ( !_playerName || (0 !=_isHuman && 1 != _isHuman) || !_numOfDecks || (0 !=_isJokerInclude && 1 != _isJokerInclude) )
    {
        return FAILURE;
    }

    return SUCCESS;
}

static int AllocVectors(Player_t *_player)
{
    _player->m_arrOfVectors[HEART] = VectorCreate(CARDS_ON_SUIT * _player->m_numOfDecks, WITHOUT_BLOCK_SIZE);
    if (!_player->m_arrOfVectors[HEART])
    {
        return FAILURE;
    }

    _player->m_arrOfVectors[SPADE] = VectorCreate(CARDS_ON_SUIT * _player->m_numOfDecks, WITHOUT_BLOCK_SIZE);
    if (!_player->m_arrOfVectors[SPADE])
    {
        VectorDestroy(_player->m_arrOfVectors[HEART]);
        return FAILURE;
    }

    _player->m_arrOfVectors[DIAMOND] = VectorCreate(CARDS_ON_SUIT * _player->m_numOfDecks, WITHOUT_BLOCK_SIZE);
    if (!_player->m_arrOfVectors[DIAMOND])
    {
        VectorDestroy(_player->m_arrOfVectors[HEART]);
        VectorDestroy(_player->m_arrOfVectors[SPADE]);
        return FAILURE;
    }

    _player->m_arrOfVectors[CLUB] = VectorCreate(CARDS_ON_SUIT * _player->m_numOfDecks, WITHOUT_BLOCK_SIZE);
    if (!_player->m_arrOfVectors[CLUB])
    {
        VectorDestroy(_player->m_arrOfVectors[HEART]);
        VectorDestroy(_player->m_arrOfVectors[SPADE]);
        VectorDestroy(_player->m_arrOfVectors[DIAMOND]);        
        return FAILURE;
    }

    if (_player->m_isJokerInclude)
    {
         _player->m_arrOfVectors[JOKER] = VectorCreate(NUM_OF_JOKERS * _player->m_numOfDecks, WITHOUT_BLOCK_SIZE);
        if (NULL == _player->m_arrOfVectors[JOKER])
        {
            VectorDestroy(_player->m_arrOfVectors[HEART]);
            VectorDestroy(_player->m_arrOfVectors[SPADE]);
            VectorDestroy(_player->m_arrOfVectors[DIAMOND]);     
            VectorDestroy(_player->m_arrOfVectors[CLUB]);        
            return FAILURE;
        }
    }

    return SUCCESS;
}