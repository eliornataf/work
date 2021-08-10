#include <stdlib.h> /* malloc, free */
#include "listIter.h" /* List Iterator Header */
#include "internal.h" /* Internal Header */
#include "listFunctions.h" /* List Function Header */

#define STOP (0)
#define CONTINUE (1)

typedef enum Status
{
    SUCCESS = 0,
    FAILURE = 1
} Status_t;

/************************************************************/

typedef int (*ProvidedFunc_t)(void *element, void *context);
typedef int (*TranslatorFunc_t)(int funcReturnValue, void *translatorContext);

/************************************************************/

typedef struct TranslatorContext
{
    ProvidedFunc_t m_providedFunc;
    void *m_providedFuncContext;
    TranslatorFunc_t m_translatorFunc;
    void *m_translatorFuncContext;
} TranslatorContext_t;

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static int TranslatorFuncFindFirst(int _providedFuncStatus, void *_translatorFunctionContext);
static int TranslatorFuncCountIf(int _providedFuncStatus, void *_translatorFunctionContext);
static int TranslatorFuncForEach(int _providedFuncStatus, void *_translatorFunctionContext);
static ListIter_t InternalForEach(ListIter_t _fromIter, ListIter_t _toIter, TranslatorContext_t *_translatorContext);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

ListIter_t ListIterFindFirst(ListIter_t _fromIter, ListIter_t _toIter, PredicateFunc_t _predicateFunc, void *_context)
{
    TranslatorContext_t *tanslatorContext = NULL;
    ListIter_t foundIter = NULL;

    if (!_fromIter || !_toIter || !_predicateFunc || !_context)
    {
        return NULL;
    }

    tanslatorContext = (TranslatorContext_t*)malloc(sizeof(TranslatorContext_t));
    if (!tanslatorContext)
    {
        return NULL;
    }

    tanslatorContext->m_providedFunc = _predicateFunc;
    tanslatorContext->m_providedFuncContext = _context;
    tanslatorContext->m_translatorFunc = TranslatorFuncFindFirst;
    tanslatorContext->m_translatorFuncContext = NULL;

    foundIter = InternalForEach(_fromIter, _toIter, tanslatorContext);

    free(tanslatorContext);

    return foundIter;
}

size_t ListIterCountIf(ListIter_t _fromIter, ListIter_t _toIter, PredicateFunc_t _predicateFunc, void *_context)
{
    TranslatorContext_t *tanslatorContext = NULL;
    size_t counter = 0;

    if (!_fromIter || !_toIter || !_predicateFunc || !_context)
    {
        return COUNT_IF_POINTER_NOT_INITIALIZE;
    }

    tanslatorContext = (TranslatorContext_t*)malloc(sizeof(TranslatorContext_t));
    if (!tanslatorContext)
    {
        return COUNT_IF_ALLOCATION_FAILED;
    }

    tanslatorContext->m_providedFunc = _predicateFunc;
    tanslatorContext->m_providedFuncContext = _context;
    tanslatorContext->m_translatorFunc = TranslatorFuncCountIf;
    tanslatorContext->m_translatorFuncContext = &counter;

    InternalForEach(_fromIter, _toIter, tanslatorContext);

    free(tanslatorContext);

    return counter;
}

ListIter_t ListIterForEach(ListIter_t _fromIter, ListIter_t _toIter, ActionFunc_t _actionFunc, void *_context)
{
    TranslatorContext_t *tanslatorContext = NULL;
    ListIter_t lastIter = NULL;

    if (!_fromIter || !_toIter || !_actionFunc)
    {
        return NULL;
    }

    tanslatorContext = (TranslatorContext_t*)malloc(sizeof(TranslatorContext_t));
    if (!tanslatorContext)
    {
        return NULL;
    }

    tanslatorContext->m_providedFunc = _actionFunc;
    tanslatorContext->m_providedFuncContext = _context;
    tanslatorContext->m_translatorFunc = TranslatorFuncForEach;
    tanslatorContext->m_translatorFuncContext = NULL;

    lastIter = InternalForEach(_fromIter, _toIter, tanslatorContext);

    free(tanslatorContext);

    return lastIter;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static int TranslatorFuncFindFirst(int _providedFuncStatus, void *_translatorFunctionContext)
{
    (void)_translatorFunctionContext;

    if (_providedFuncStatus)
    {
        return STOP;
    }

    return CONTINUE;
}

static int TranslatorFuncCountIf(int _providedFuncStatus, void *_translatorFunctionContext)
{
    if (_providedFuncStatus)
    {
        ++*(size_t*)_translatorFunctionContext;
    }

    return CONTINUE;
}

static int TranslatorFuncForEach(int _providedFuncStatus, void *_translatorFunctionContext)
{
    (void)_translatorFunctionContext;

    if (!_providedFuncStatus)
    {
        return STOP;
    }

    return CONTINUE;
}

static ListIter_t InternalForEach(ListIter_t _fromIter, ListIter_t _toIter, TranslatorContext_t *_translatorContext)
{
    int providedFuncStatus;

    for (;_fromIter != _toIter;_fromIter = ListIterNext(_fromIter))
    {
        providedFuncStatus = _translatorContext->m_providedFunc(ListIterGet(_fromIter),_translatorContext->m_providedFuncContext);

        if (!_translatorContext->m_translatorFunc(providedFuncStatus, _translatorContext->m_translatorFuncContext))
        {
            break;
        }
    }

    return _fromIter;
}