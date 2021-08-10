#include <stdlib.h> /* malloc, free */
#include "round.h" /* Game Header */
#include "deck.h" /* Deck Header */
#include "cards.h" /* Cards Header */
#include "dynamicVector.h" /* Dynamic Vector header */
#include "player.h" /* Player Header */
#include "UI.h" /* UI Header */

#define CARDS_ON_SUIT (13)
#define NUM_OF_SUITS (4)
#define NUM_OF_JOKERS (2)
#define WITHOUT_BLOCK_SIZE (0)
#define TRICKS_IN_ROUND (13)
#define INSIGMIFICANT_DATA_CARD (100)
#define IS_NOT_PRESENTED (0)
#define IS_PRESENTED (1)
#define SUIT_IS_EMPTY (-1)
#define SPADE_QUEEN_VALUE (13)
#define POP_DATA_ERROR (-2)
#define TAKE_THREE_CARDS (3)
#define WITHOUT_JOKERS (0)
#define CARDS_IN_TRICK (13)
#define NOT_PRINT (0)
#define PRINT (1)

struct Round
{
    size_t m_numOfPlayers;
    size_t m_numOfDecks;
    size_t m_isJokerInclude;
    size_t m_numOfTrick;
    int m_isHeartCardPresented;
    Player_t **m_playersArr;
    Vector_t *m_playBoard;
};

enum GiveThreeCardsByTrick
{
    CARDS_GO_TO_THE_LEFT = 0,
    CARDS_GO_TO_THE_RIGHT = 1,
    CARDS_GO_TO_FRONT_OF_ME = 2,
    CARDS_DONT_GO_TO = 3
} GiveThreeCardsByTrick_t;

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static int SortPlayersCards(Round_t *_round);
static size_t FindThePlayerHowTakeTheThreeCardsStrategy(size_t _currIndex, size_t _trickThreeCardAction, size_t _numOfPlayers);
static int SearchCardInVectors(Vector_t **_arrOfVectors, size_t _humanCardInput, CardSuit_t *_foundSuit, size_t *_foundIndex, size_t *_vecNumOfElements);
static int HumanPlayerPopElementData(Vector_t **_arrOfVectors, size_t _humanCardInput, CardSuit_t _foundsuit, size_t _foundIndex, size_t _vecNumOfElements);
static int HumanThreeCardsStrategy(Vector_t **_arrOfVectors, CardSuit_t _cardSuit, int *_isHeartCardPresented, size_t _numOfTrick);
static int ComputerThreeCardsStrategy(Vector_t **_arrOfVectors, CardSuit_t _cardSuit, int *_isHeartCardPresented, size_t _numOfTrick);
static int ThreeCardsAction(Round_t *_round);
static size_t FindStartingPlayerFirstTrick(Round_t *_round);
static int ComputerPopFirstElement(Vector_t **arrOfVectors, CardSuit_t _cardSuit);
static int ComputerGamePlayStrategyStartingPlayer(Vector_t **arrOfVectors, CardSuit_t _cardSuit, int *_isHeartCardPresented, size_t _numOfTrick);
static int ComputerGamePlayStrategyIsNotStartingPlayer(Vector_t **_arrOfVectors, CardSuit_t _cardSuit, int *_isHeartCardPresented, size_t _numOfTrick);
static int HumanGamePlayStrategyStartingPlayer(Vector_t **_arrOfVectors, CardSuit_t _cardSuit, int *_isHeartCardPresented, size_t _numOfTrick);
static int HumanGamePlayStrategyIsNotStartingPlayer(Vector_t **_arrOfVectors, CardSuit_t _cardSuit, int *_isHeartCardPresented, size_t _numOfTrick);
static int PutCardOnTable(Round_t *_round, size_t _startingPlayer);
static size_t CalcLoserScore(Round_t *_round);
static int FindLoserAndCalcScore(Round_t *_round, size_t _startingPlayer, size_t *_loserIndex, size_t *_loserScore);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Round_t *CreateRound(size_t _numOfPlayers, size_t _numOfDecks, int _isJokerInclude, Player_t **_playersArr)
{
    Round_t *round = NULL;
    
    if (!_playersArr || !*_playersArr)
    {
        return NULL;
    }

    round = (Round_t*)malloc(sizeof(Round_t));
    if (!round)
    {
        return NULL;
    }

    round->m_numOfPlayers = _numOfPlayers;
    round->m_numOfDecks = _numOfDecks;
    round->m_isJokerInclude = _isJokerInclude;
    round->m_numOfTrick = 0;
    round->m_isHeartCardPresented = IS_NOT_PRESENTED;
    round->m_playersArr = _playersArr;

    round->m_playBoard = VectorCreate(_numOfPlayers, WITHOUT_BLOCK_SIZE);
    if (!round->m_playBoard)
    {
        free(round);
        return NULL;
    }

    return round;
}

void DestroyRound(Round_t *_round)
{
    if (!_round)
    {
        return;
    }

    VectorDestroy(_round->m_playBoard);
    free(_round);
}

int RunRound(Round_t *_round, int *_scoreBoard)
{
    Deck_t *deck = NULL;
    int drawCardData;
    size_t i, j, startingPlayer, loserIndex, loserScore;

    if (!_round || !_scoreBoard)
    {
        return FAILURE;
    }

    deck = CreateDeck(_round->m_numOfDecks, _round->m_isJokerInclude); 
    if (!deck)
    {
        return FAILURE;
    }

    if (FAILURE == ShuffleDeck(deck))
    {
        DestroyDeck(deck);
        return FAILURE;
    }

    for (i = 0, j = ( ( CARDS_ON_SUIT * NUM_OF_SUITS + NUM_OF_JOKERS * _round->m_isJokerInclude ) * _round->m_numOfDecks);0 < j;--j, i = (i + 1) % _round->m_numOfPlayers)
    {
        drawCardData = DrawCardFromDeck(deck); 
        if (DRAW_CARD_FAILED == drawCardData)
        {
            DestroyDeck(deck);
            return FAILURE;
        }

        if (FAILURE == PlayerGetCard(_round->m_playersArr[i], drawCardData))
        {
            DestroyDeck(deck);
            return FAILURE;
        }
    }

    if (FAILURE == SortPlayersCards(_round))
    {
        DestroyDeck(deck);
        return FAILURE;
    }

    if (FAILURE == ThreeCardsAction(_round))
    {
        DestroyDeck(deck);
        return FAILURE;
    }

    if (FAILURE == SortPlayersCards(_round))
    {
        DestroyDeck(deck);
        return FAILURE;
    }

    for (i = 0;i < TRICKS_IN_ROUND;++i)
    {
        PrintNumOfTrick(_round->m_numOfTrick);
        
        if (!i)
        {
            startingPlayer = FindStartingPlayerFirstTrick(_round);
        }

        if (FAILURE == PutCardOnTable(_round, startingPlayer))
        {

            DestroyDeck(deck);
            return FAILURE;
        }

        PrintTable(_round->m_playBoard, _round->m_numOfPlayers);

        if (FAILURE == FindLoserAndCalcScore(_round, startingPlayer, &loserIndex, &loserScore))
        {
            DestroyDeck(deck);
            return FAILURE;
        }

        _scoreBoard[loserIndex] += loserScore;

        PrintScoreBoard(_scoreBoard, _round->m_numOfPlayers, startingPlayer);

        if (FAILURE == SortPlayersCards(_round))
        {            
            DestroyDeck(deck);
            return FAILURE;
        }

        PrintTrickCalc(startingPlayer, loserIndex, loserScore);

        startingPlayer = loserIndex;

        ++_round->m_numOfTrick;

        sleep(2);
    }

    DestroyDeck(deck);

    return SUCCESS;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static int SortPlayersCards(Round_t *_round)
{
    size_t i;

    for (i = 0;i < _round->m_numOfPlayers;++i)
    {
        if (OK != SortPlayerCardsByRank(_round->m_playersArr[i]))
        {
            return FAILURE;
        }
    }

    return SUCCESS;
}

static size_t FindThePlayerHowTakeTheThreeCardsStrategy(size_t _currIndex, size_t _trickThreeCardAction, size_t _numOfPlayers)
{
    if (CARDS_GO_TO_THE_LEFT == _trickThreeCardAction)
    {
        return (!_currIndex) ? _numOfPlayers - 1 : _currIndex - 1;
    }

    if (CARDS_GO_TO_THE_RIGHT == _trickThreeCardAction)
    {
        return (_currIndex + 1) % _numOfPlayers;
    }
    
    if (CARDS_GO_TO_FRONT_OF_ME == _trickThreeCardAction)
    {
        return (_currIndex + 2) % _numOfPlayers;
    }
}

static int SearchCardInVectors(Vector_t **_arrOfVectors, size_t _humanCardInput, CardSuit_t *_foundSuit, size_t *_foundIndex, size_t *_vecNumOfElements)
{
    int currElementData;
    size_t i;

    *_foundSuit = FindCardSuit(_humanCardInput);
    if (SUIT_ERROR == *_foundSuit || JOKER == *_foundSuit)
    {
        return IS_NOT_FOUND;
    }

    VectorNumOfElements(_arrOfVectors[*_foundSuit], _vecNumOfElements);

    for (i = 0;i < *_vecNumOfElements;++i)
    {
        VectorGetElement(_arrOfVectors[*_foundSuit], i, &currElementData);
        if ((int)_humanCardInput == currElementData)
        {
            *_foundIndex = i;
            return IS_FOUND;
        }
    }

    return IS_NOT_FOUND;
}

static int HumanPlayerPopElementData(Vector_t **_arrOfVectors, size_t _humanCardInput, CardSuit_t _foundsuit, size_t _foundIndex, size_t _vecNumOfElements)
{
    int popElementData, lastElementData;

    if (1 == _vecNumOfElements)
    {
        if (OK != VectorPop(_arrOfVectors[_foundsuit], &popElementData))
        {
            return POP_DATA_ERROR;
        }

        return popElementData;
    }

    VectorGetElement(_arrOfVectors[_foundsuit], _vecNumOfElements - 1, &lastElementData);

    VectorSetElement(_arrOfVectors[_foundsuit], _foundIndex, lastElementData);
    VectorSetElement(_arrOfVectors[_foundsuit], _vecNumOfElements - 1, _humanCardInput);

    if (OK != VectorPop(_arrOfVectors[_foundsuit], &popElementData))
    {
        return POP_DATA_ERROR;
    }
        
    return popElementData;
}

static int HumanThreeCardsStrategy(Vector_t **_arrOfVectors, CardSuit_t _cardSuit, int *_isHeartCardPresented, size_t _numOfTrick)
{
    size_t humanCardInput, foundIndex, vecNumOfElements;
    int printErrorMessage = NOT_PRINT;
    CardSuit_t foundSuit;

    (void)_cardSuit;
    (void)_isHeartCardPresented;
    (void)_numOfTrick;

    PrintPlayerHand(_arrOfVectors, WITHOUT_JOKERS);

    do
    {
        CheckPlayerInvalidInput(&printErrorMessage);        

        humanCardInput = GetCardFromHumanPlayer();
    } 
    while (IS_NOT_FOUND == SearchCardInVectors(_arrOfVectors, humanCardInput, &foundSuit, &foundIndex, &vecNumOfElements));

    return HumanPlayerPopElementData(_arrOfVectors, humanCardInput, foundSuit, foundIndex, vecNumOfElements);
}

static int ComputerThreeCardsStrategy(Vector_t **_arrOfVectors, CardSuit_t _cardSuit, int *_isHeartCardPresented, size_t _numOfTrick)
{
    size_t i, vecNumOfElements;
    int givenCardData;

    (void)_cardSuit;
    (void)_isHeartCardPresented;
    (void)_numOfTrick;

    for (i = 0;i < NUM_OF_SUITS;++i)
    {
        VectorNumOfElements(_arrOfVectors[i], &vecNumOfElements);

        if (vecNumOfElements)
        {
            if(OK != VectorPop(_arrOfVectors[i], &givenCardData))
            {
                return FAILURE;
            }

            break;
        }
    }

    return givenCardData;
}

static int ThreeCardsAction(Round_t *_round)
{
    size_t trickThreeCardAction = _round->m_numOfTrick % _round->m_numOfPlayers;
    size_t i, j, indexOfFoundPlayerToTake;
    int givenCardData, isHuman;

    if (CARDS_DONT_GO_TO != trickThreeCardAction)
    {
        for (i = 0;i < _round->m_numOfPlayers;++i)
        {
            indexOfFoundPlayerToTake = FindThePlayerHowTakeTheThreeCardsStrategy(i, trickThreeCardAction, _round->m_numOfPlayers);

            isHuman = PlayerIsHuman(_round->m_playersArr[i]);

            if (isHuman)
            {
                PrintThreeCardToRotateMessage();
            }

            for (j = 0;j < TAKE_THREE_CARDS;++j)
            {
                if (isHuman)
                {
                    givenCardData = PlayerGiveCard(_round->m_playersArr[i], INSIGMIFICANT_DATA_CARD, &_round->m_isHeartCardPresented, _round->m_numOfTrick, HumanThreeCardsStrategy);
                    if (ERROR_GIVE_CARD == givenCardData)
                    {
                        return FAILURE;
                    }
                }
                else
                {
                    givenCardData = PlayerGiveCard(_round->m_playersArr[i], INSIGMIFICANT_DATA_CARD, &_round->m_isHeartCardPresented, _round->m_numOfTrick, ComputerThreeCardsStrategy);
                    if (ERROR_GIVE_CARD == givenCardData)
                    {
                        return FAILURE;
                    }
                }

                if (SUCCESS != PlayerGetCard(_round->m_playersArr[indexOfFoundPlayerToTake], givenCardData))
                {
                    return FAILURE;
                }
            }
        }
    }

    return SUCCESS;
}

static size_t FindStartingPlayerFirstTrick(Round_t *_round)
{
    size_t i;

    for (i = 0;i < _round->m_numOfPlayers;++i)
    {
        if (IS_FOUND == PlayerSearchCardByIndex(_round->m_playersArr[i], CLUB_2))
        {
            break;
        }
    }

    return i;
}

static int ComputerPopFirstElement(Vector_t **arrOfVectors, CardSuit_t _cardSuit)
{
    int popElementData, firstElementData, lastElementData;
    size_t vecNumOfElements;

    VectorNumOfElements(arrOfVectors[_cardSuit], &vecNumOfElements);

    if (0 != vecNumOfElements)
    {
        if (1 == vecNumOfElements)
        {
            if (OK != VectorPop(arrOfVectors[_cardSuit], &popElementData))
            {
                return POP_DATA_ERROR;
            }            
            
            return popElementData;
        }
                
        VectorGetElement(arrOfVectors[_cardSuit], 0, &firstElementData);
        VectorGetElement(arrOfVectors[_cardSuit], vecNumOfElements - 1, &lastElementData);

        VectorSetElement(arrOfVectors[_cardSuit], 0, lastElementData);
        VectorSetElement(arrOfVectors[_cardSuit], vecNumOfElements - 1, firstElementData);

        if (OK != VectorPop(arrOfVectors[_cardSuit], &popElementData))
        {
            return POP_DATA_ERROR;
        }

        return popElementData;
    }
    else
    {
        return SUIT_IS_EMPTY;
    }
}

static int ComputerGamePlayStrategyStartingPlayer(Vector_t **arrOfVectors, CardSuit_t _cardSuit, int *_isHeartCardPresented, size_t _numOfTrick)
{
    int popElementData;
    size_t i;

    (void)_cardSuit;

    if (!(_numOfTrick % TRICKS_IN_ROUND))
    {
        popElementData = ComputerPopFirstElement(arrOfVectors, CLUB);
        if (POP_DATA_ERROR == popElementData)
        {
            return POP_DATA_ERROR;
        }

        return popElementData;
    }
    
    if (*_isHeartCardPresented)
    {   
        popElementData = ComputerPopFirstElement(arrOfVectors, HEART);

        if (POP_DATA_ERROR == popElementData)
        {
            return POP_DATA_ERROR;
        }

        if (SUIT_IS_EMPTY != popElementData)
        {
            return popElementData;
        }
    }

    for (i = SPADE;i < NUM_OF_SUITS;++i)
    {
        popElementData = ComputerPopFirstElement(arrOfVectors, i);
            
        if (POP_DATA_ERROR == popElementData)
        {
            return POP_DATA_ERROR;
        }

        if ((!(_numOfTrick % TRICKS_IN_ROUND)) && SPADE_Q == popElementData)
        {
            VectorPush(arrOfVectors[SPADE], popElementData);
            popElementData = SUIT_IS_EMPTY;
        }
            
        if (SUIT_IS_EMPTY != popElementData)
        {                                            
            return popElementData;
        }
    }

    popElementData = ComputerPopFirstElement(arrOfVectors, HEART);

    if (POP_DATA_ERROR == popElementData)
    {
        return POP_DATA_ERROR;
    }
            
    if (SUIT_IS_EMPTY != popElementData)
    {
        return popElementData;
    }
}

static int ComputerGamePlayStrategyIsNotStartingPlayer(Vector_t **_arrOfVectors, CardSuit_t _cardSuit, int *_isHeartCardPresented, size_t _numOfTrick)
{
    int popElementData;
    size_t i;

    (void)_numOfTrick;

    popElementData = ComputerPopFirstElement(_arrOfVectors, _cardSuit);

    if (POP_DATA_ERROR == popElementData)
    {
        return POP_DATA_ERROR;
    }

    if (SUIT_IS_EMPTY != popElementData)
    {
        return popElementData;
    }

    for (i = HEART;i < NUM_OF_SUITS;++i)
    {
        if (_cardSuit == i)
        {
            ++i;
        }

        popElementData = ComputerPopFirstElement(_arrOfVectors, i);
            
        if (POP_DATA_ERROR == popElementData)
        {
            return POP_DATA_ERROR;
        }
            
        if (SUIT_IS_EMPTY != popElementData)
        {
            if (HEART == i && !*_isHeartCardPresented)
            {
                *_isHeartCardPresented = IS_PRESENTED;
            }

            return popElementData;
        }
    }
}

static int HumanGamePlayStrategyStartingPlayer(Vector_t **_arrOfVectors, CardSuit_t _cardSuit, int *_isHeartCardPresented, size_t _numOfTrick)
{
    size_t humanCardInput, foundIndex, vecNumOfElements;
    CardSuit_t foundSuit;
    int popElementData, isFound;
    int printErrorMessage = NOT_PRINT;

    (void)_cardSuit;

    if (!(_numOfTrick % TRICKS_IN_ROUND))
    {
        PrintYouAreTheStartingPlayerOfTheRound();        
        PrintPlayerHand(_arrOfVectors, WITHOUT_JOKERS);

        do
        {
            CheckPlayerInvalidInput(&printErrorMessage);        

            humanCardInput = GetCardFromHumanPlayer();
        } 
        while (CLUB_2 != humanCardInput);

        popElementData = ComputerPopFirstElement(_arrOfVectors, CLUB);
        if (POP_DATA_ERROR == popElementData)
        {
            return POP_DATA_ERROR;
        }

        return popElementData;
    }
    else
    {
        PrintYouAreTheStartingPlayerOfTheTrick();
        PrintPlayerHand(_arrOfVectors, WITHOUT_JOKERS);

        if (!(*_isHeartCardPresented))
        {
            do
            {
                CheckPlayerInvalidInput(&printErrorMessage);        

                humanCardInput = GetCardFromHumanPlayer();

                isFound = SearchCardInVectors(_arrOfVectors, humanCardInput, &foundSuit, &foundIndex, &vecNumOfElements);
            } 
            while (HEART == foundSuit);
        }
        else
        {
            do
            {
                CheckPlayerInvalidInput(&printErrorMessage);        

                humanCardInput = GetCardFromHumanPlayer();

                isFound = SearchCardInVectors(_arrOfVectors, humanCardInput, &foundSuit, &foundIndex, &vecNumOfElements);
            } 
            while (IS_NOT_FOUND == isFound);
        }
    }

    return HumanPlayerPopElementData(_arrOfVectors, humanCardInput, foundSuit, foundIndex, vecNumOfElements);
}

static int HumanGamePlayStrategyIsNotStartingPlayer(Vector_t **_arrOfVectors, CardSuit_t _cardSuit, int *_isHeartCardPresented, size_t _numOfTrick)
{
    size_t humanCardInput, foundIndex, vecNumOfElements, vecCardSuitNumOfElements;
    int printErrorMessage = NOT_PRINT;
    CardSuit_t foundSuit;
    int isFound;

    (void)*_isHeartCardPresented;

    PrintPleaseChooseCardToPlay();

    VectorNumOfElements(_arrOfVectors[_cardSuit], &vecCardSuitNumOfElements);

    PrintPlayerHand(_arrOfVectors, WITHOUT_JOKERS);

    if (vecCardSuitNumOfElements)
    {
        do
        {
            CheckPlayerInvalidInput(&printErrorMessage);        

            humanCardInput = GetCardFromHumanPlayer();

            isFound = SearchCardInVectors(_arrOfVectors, humanCardInput, &foundSuit, &foundIndex, &vecNumOfElements);
        } 
        while (_cardSuit != foundSuit || IS_NOT_FOUND == isFound || (!_numOfTrick && SPADE_Q == humanCardInput));
    }
    else
    {
        do
        {
            CheckPlayerInvalidInput(&printErrorMessage);        

            humanCardInput = GetCardFromHumanPlayer();

            isFound = SearchCardInVectors(_arrOfVectors, humanCardInput, &foundSuit, &foundIndex, &vecNumOfElements);
        } 
        while (IS_NOT_FOUND == isFound || (!_numOfTrick && SPADE_Q == humanCardInput));
    }

    return HumanPlayerPopElementData(_arrOfVectors, humanCardInput, foundSuit, foundIndex, vecNumOfElements);
}

static int PutCardOnTable(Round_t *_round, size_t _startingPlayer)
{
    int givenCardData, firstElementData, isHuman;
    size_t i, j;

    for (i = 0, j = _startingPlayer;i < _round->m_numOfPlayers;++i, j = (j + 1) % _round->m_numOfPlayers)
    {
        isHuman = PlayerIsHuman(_round->m_playersArr[j]);

        if (isHuman)
        {
            PrintTable(_round->m_playBoard, _round->m_numOfPlayers);

            if (_startingPlayer == j)
            {
                givenCardData = PlayerGiveCard(_round->m_playersArr[j], INSIGMIFICANT_DATA_CARD, &_round->m_isHeartCardPresented, _round->m_numOfTrick, HumanGamePlayStrategyStartingPlayer);
                if (ERROR_GIVE_CARD == givenCardData)
                {   
                    return FAILURE;
                }
            }
            else
            {
                VectorGetElement(_round->m_playBoard, 0, &firstElementData);

                givenCardData = PlayerGiveCard(_round->m_playersArr[j], firstElementData, &_round->m_isHeartCardPresented, _round->m_numOfTrick, HumanGamePlayStrategyIsNotStartingPlayer);
                if (ERROR_GIVE_CARD == givenCardData)
                {   
                    return FAILURE;
                }
            }
        }
        else
        {
            if (_startingPlayer == j)
            {
                givenCardData = PlayerGiveCard(_round->m_playersArr[j], INSIGMIFICANT_DATA_CARD, &_round->m_isHeartCardPresented, _round->m_numOfTrick, ComputerGamePlayStrategyStartingPlayer);
                if (ERROR_GIVE_CARD == givenCardData)
                {   
                    return FAILURE;
                }
            }
            else
            {
                VectorGetElement(_round->m_playBoard, 0, &firstElementData);

                givenCardData = PlayerGiveCard(_round->m_playersArr[j], firstElementData, &_round->m_isHeartCardPresented, _round->m_numOfTrick, ComputerGamePlayStrategyIsNotStartingPlayer);
                if (ERROR_GIVE_CARD == givenCardData)
                {   
                    return FAILURE;
                }
            }
        }

        if (OK != VectorPush(_round->m_playBoard, givenCardData))
        {
            return FAILURE;
        }
    }

    return SUCCESS;
}
 
static size_t CalcLoserScore(Round_t *_round)
{
    CardSuit_t currCardSuit;
    size_t countScore = 0;
    int currCardData;
    size_t i;

    for (i = 0;i < _round->m_numOfPlayers;++i)
    {
        VectorGetElement(_round->m_playBoard, i, &currCardData);

        currCardSuit = FindCardSuit(currCardData);
        if (SUIT_ERROR == currCardSuit || JOKER == currCardSuit)
        {
            return FAILURE;
        }

        if (HEART == currCardSuit)
        {
            ++countScore;
        }
        else if (SPADE_Q == currCardData)
        {
            countScore += SPADE_QUEEN_VALUE;
        }
    }

    return countScore;
}

static int FindLoserAndCalcScore(Round_t *_round, size_t _startingPlayer, size_t *_loserIndex, size_t *_loserScore)
{
    CardSuit_t firstCardSuit, currCardSuit;
    int maxCardData, currCardData;
    size_t i, j;

    *_loserIndex = _startingPlayer;

    VectorGetElement(_round->m_playBoard, 0, &maxCardData);
    
    firstCardSuit = FindCardSuit(maxCardData);
    if (SUIT_ERROR == firstCardSuit || JOKER == firstCardSuit)
    {
        return FAILURE;
    }

    for (i = 1, j = (_startingPlayer + 1) % _round->m_numOfPlayers;i < _round->m_numOfPlayers;++i, j = (j + 1) % _round->m_numOfPlayers)
    {
        VectorGetElement(_round->m_playBoard, i, &currCardData);

        currCardSuit = FindCardSuit(currCardData);
        if (SUIT_ERROR == currCardSuit || JOKER == currCardSuit)
        {
            return FAILURE;
        }

        if (firstCardSuit == currCardSuit && maxCardData < currCardData)
        {
            *_loserIndex = j;
            maxCardData = currCardData;
        }
    }

    *_loserScore = CalcLoserScore(_round);

    for (i = 0;i < _round->m_numOfPlayers;++i)
    {
        if (OK != VectorPop(_round->m_playBoard, &currCardData))
        {
            return FAILURE;
        }
    }

    return SUCCESS;
}