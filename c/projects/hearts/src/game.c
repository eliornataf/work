#include <stdlib.h> /* malloc, free */
#include <string.h> /* strcat */
#include "game.h" /* Game Header */
#include "player.h" /* Player Header */
#include "round.h" /* Game Header */

#define STR_LENGTH (100)
#define IS_NOT_HUMAN (0)
#define IS_HUMAN (1)
#define NUM_OF_CHAR_TO_CONCAT (1)
#define CURR_PLAYER (0)

/*****************************************/

struct Game
{
    size_t m_numOfPlayers;
    size_t m_numOfDecks;
    size_t m_isJokerInclude;
    size_t m_numOfRounds;
    size_t m_scoreToEnd;
    size_t m_numOfHumanPlayers;
    int *m_scoreBoard;
    Player_t **m_arrOfPlayers;
};

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static int CheckInputs(size_t _numOfPlayers, size_t _numOfDecks, int _isJokerInclude, size_t _scoreToEnd, size_t _numOfHumanPlayers);
static void FreePlayers(Game_t *_game, size_t _lastAllocIndex);
static int CreateNewPlayers(Game_t *_game);
static int GetTheHighestPlayerScore(Game_t *_game);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

Game_t *CreateGame(size_t _numOfPlayers, size_t _numOfDecks, int _isJokerInclude, size_t _scoreToEnd, size_t _numOfHumanPlayers)
{
    Game_t *game = NULL;
    int status;

    if (FAILURE == CheckInputs(_numOfPlayers, _numOfDecks, _isJokerInclude, _scoreToEnd, _numOfHumanPlayers))
    {
        return NULL;
    }

    game = (Game_t*)malloc(sizeof(Game_t));
    if (!game)
    {
        return NULL;
    }

    game->m_numOfPlayers = _numOfPlayers;
    game->m_numOfDecks = _numOfDecks;
    game->m_isJokerInclude = _isJokerInclude;
    game->m_numOfRounds = 0;
    game->m_scoreToEnd = _scoreToEnd;
    game->m_numOfHumanPlayers = _numOfHumanPlayers;

    game->m_scoreBoard = (int*)calloc(_numOfPlayers, sizeof(int));
    if (!game->m_scoreBoard)
    {
        free(game);
        return NULL;
    }

    game->m_arrOfPlayers = (Player_t**)malloc(_numOfPlayers * sizeof(Player_t*));
    if (!game->m_arrOfPlayers)
    {
        free(game->m_scoreBoard);
        free(game);
        return NULL;
    }

    status = CreateNewPlayers(game);
    if (FAILURE == status)
    {
        free(game->m_arrOfPlayers);
        free(game->m_scoreBoard);
        free(game);
        return NULL;
    }

    return game;
}

void DestroyGame(Game_t *_game)
{
    if (!_game)
    {
        return;
    }

    FreePlayers(_game, _game->m_numOfPlayers);
    free(_game->m_arrOfPlayers);
    free(_game->m_scoreBoard);
    free(_game);
}

int RunGame(Game_t *_game)
{
    Round_t *round = NULL;
    int status = SUCCESS;

    if (!_game)
    {
        return FAILURE;
    }

    round = CreateRound(_game->m_numOfPlayers, _game->m_numOfDecks, _game->m_isJokerInclude, _game->m_arrOfPlayers);
    if (!round)
    {
        return FAILURE;
    }

    PrintWelcomeToTheGame();

    do
    {
        status = RunRound(round, _game->m_scoreBoard);
        if (FAILURE == status)
        {
            break;
        }

        PrintMessageScoreTableAfterRound(_game->m_numOfRounds);

        PrintScoreBoard(_game->m_scoreBoard, _game->m_numOfPlayers, CURR_PLAYER);

        ++_game->m_numOfRounds;
    }
    while ((size_t)GetTheHighestPlayerScore(_game) < _game->m_scoreToEnd);
    
    if (FAILURE != status)
    {
        PrintFinalScoreBoard(_game->m_scoreBoard, _game->m_numOfPlayers);
    }

    PrintGoodByeMessage();

    DestroyRound(round);
    DestroyGame(_game);

    return status;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static int CheckInputs(size_t _numOfPlayers, size_t _numOfDecks, int _isJokerInclude, size_t _scoreToEnd, size_t _numOfHumanPlayers)
{
    if ( (!_numOfPlayers) || (1 == _numOfPlayers) || (!_numOfDecks) || (0 !=_isJokerInclude && 1 != _isJokerInclude) || (!_scoreToEnd) ||  (_numOfPlayers <= _numOfHumanPlayers) )
    {
        return FAILURE;
    }

    return SUCCESS;
}

static void FreePlayers(Game_t *_game, size_t _lastAllocIndex)
{
    int i;

    for (i = _lastAllocIndex - 1;0 <= i;--i)
    {
        DestroyPlayer(_game->m_arrOfPlayers[i]);
    }
}

static int CreateNewPlayers(Game_t *_game)
{
    Player_t *player = NULL;
    char humanStr[STR_LENGTH];
    char computerStr[STR_LENGTH];
    char countHumanPlayer = '0';
    char countComputerPlayer = '0';
    int allocStatus = SUCCESS;
    size_t arrOfPlayersIndex = 0;
    size_t i;
    
    for (i = 0;i < _game->m_numOfHumanPlayers;++i)
    {
        strcpy(humanStr, "Human_");

        player = CreatePlayer(strncat(humanStr, &countHumanPlayer, NUM_OF_CHAR_TO_CONCAT), IS_HUMAN, _game->m_numOfDecks, _game->m_isJokerInclude);
        if (NULL == player)
        {
            allocStatus = FAILURE;
            break;
        }
        _game->m_arrOfPlayers[arrOfPlayersIndex++] = player;

        ++countHumanPlayer;
    }
    
    if (FAILURE == allocStatus && i != 0)
    {
        FreePlayers(_game, i);
        return FAILURE;
    }

    for (;i < _game->m_numOfPlayers;++i)
    {
   		strcpy(computerStr, "Computer_");

        player = CreatePlayer(strncat(computerStr, &countComputerPlayer, NUM_OF_CHAR_TO_CONCAT), IS_NOT_HUMAN, _game->m_numOfDecks, _game->m_isJokerInclude);
        if (NULL == player)
        {
            allocStatus = FAILURE;
            break;
        }

        _game->m_arrOfPlayers[arrOfPlayersIndex++] = player;

        ++countComputerPlayer;
    }

    if (FAILURE == allocStatus)
    {
        FreePlayers(_game, i);
        return FAILURE;
    }

    return SUCCESS;
}

static int GetTheHighestPlayerScore(Game_t *_game)
{
    int highestPlayerScore;
    size_t i;

    for (i = 0;i < _game->m_numOfPlayers;++i)
    {
        if (i == 0 || highestPlayerScore < _game->m_scoreBoard[i])
        {
            highestPlayerScore = _game->m_scoreBoard[i];
        }
    }

    return highestPlayerScore;
}