#include <stdlib.h> /* malloc, free, size_t */
#include "genericBinaryTree.h" /* Generic Binary Tree Header */

#define DUPLICATE_FOUND (-1)
#define GO_LEFT (0)
#define GO_RIGHT (1)

/*****************************************************************************/

struct Node
{
	void *m_data;
	Node_t *m_left;
	Node_t *m_right;
	Node_t *m_parent;
};

struct BST
{
	Node_t m_root;
    ComparatorFunc_t m_compareFunc;
};

typedef enum Side
{
    DUPLICATED = -1,
	LEFT = 0,
	RIGHT = 1,
	NUM_OF_ELEMENTS
} Side_t;

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void DestroyNodeRecuAux(Node_t *node, void (*nodeDestroy)(void *node));
static void InitNode(Node_t *newNode, void *data, Node_t *parent);
static void MoveNode(BST_t *bst, Node_t **nodeRunner, void *newNodedata, Side_t *side);
static void nodeSetParent(Node_t *newNode, Node_t *parentNode, Side_t childSide);
static Node_t *GetMostNodeFromSide(Node_t *node, Side_t side);
static Side_t CheckIterParentChildSide(BSTIter_t iter);
static void removeLeafNode(BSTIter_t iter, Side_t parentChildSide);
static void RemoveNodeWithRightSonOrLeftSon(BSTIter_t iter, Side_t parentChildSide, Side_t childSide);
static void RemoveNodeWith2Children(BSTIter_t iter, Side_t parentChildSide);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

BST_t *BSTCreate(ComparatorFunc_t _compareFunc)
{
    BST_t *bst = NULL;

    if (!_compareFunc)
    {
        return NULL;
    }

    bst = (BST_t*)malloc(sizeof(BST_t));
    if (!bst)
    {
        return NULL;
    }

    bst->m_root.m_data = NULL;
    bst->m_root.m_left = NULL;
    bst->m_root.m_right = NULL;
    bst->m_root.m_parent = &bst->m_root;

    bst->m_compareFunc = _compareFunc;

    return bst;
}

void BSTDestroy(BST_t **_bst, void (*_nodeDestroy)(void *node))
{
    if (!_bst || !*_bst)
    {
        return;
    }

    if (_nodeDestroy)
    {
        DestroyNodeRecuAux((*_bst)->m_root.m_left, _nodeDestroy);
    }

    free(*_bst);
    *_bst = NULL;
}

BSTIter_t BSTInsert(BST_t *_bst, void *_data)
{
	Node_t *newNode = NULL;
	Node_t *nodeRunner = NULL;
    Node_t *parentRunner = NULL;
    Side_t side = LEFT;

    if (!_bst)
    {
        return NULL;
    }

    if (!_data)
    {
        return BSTIterEnd(_bst);
    }

    newNode = (Node_t*)malloc(sizeof(Node_t));
	if (!newNode)
	{
		return BSTIterEnd(_bst);
	}

	nodeRunner = _bst->m_root.m_left;
    parentRunner = BSTIterEnd(_bst);

    while (nodeRunner) 
	{    
        parentRunner = nodeRunner;

	    MoveNode(_bst, &nodeRunner, _data, &side);
        if (DUPLICATED == side)
        {
            free(newNode);
            return BSTIterEnd(_bst);
        }
	}

    InitNode(newNode, _data, parentRunner);

    nodeSetParent(newNode, parentRunner, side);

    return (BSTIter_t)newNode;
}

BSTIter_t BSTFindFirst(const BST_t *_bst, PredicateFunc_t _predicateFunc, void *_context)
{
    BSTIter_t iter = NULL; 

    if (!_bst || !_predicateFunc)
    {
        return NULL;
    }

    for (iter = BSTIterBegin(_bst);!BSTIterEqual(iter, BSTIterEnd(_bst));iter = BSTIterNext(iter))
    {
        if (_predicateFunc(((Node_t*)iter)->m_data, _context))
        {
            return iter;
        }
    }

    return BSTIterEnd(_bst);
}

BSTIter_t BSTIterBegin(const BST_t *_bst)
{
    if (!_bst)
    {
        return NULL;
    }

    if (!_bst->m_root.m_left)
    {
        return BSTIterEnd(_bst);
    }

    return (BSTIter_t)GetMostNodeFromSide(_bst->m_root.m_left, LEFT);
}

BSTIter_t BSTIterEnd(const BST_t *_bst)
{
    if (!_bst)
    {             
        return NULL;
    }

    return (BSTIter_t)&_bst->m_root;
}

int BSTIterEqual(const BSTIter_t _firstIter, const BSTIter_t _secondIter)
{
    if (!_firstIter || !_secondIter)
    {
        return POINTER_NOT_INITIALIZE_EQUAL;
    }

    return (_firstIter == _secondIter);
}

BSTIter_t BSTIterNext(BSTIter_t _iter)
{
    if (!_iter)
    {
        return NULL;
    }

    if (((Node_t*)_iter)->m_right) 
    {
        _iter = ((Node_t*)_iter)->m_right;

        _iter = GetMostNodeFromSide((Node_t*)_iter, LEFT);
    }
    else if (!BSTIterEqual(_iter, (BSTIter_t)((Node_t*)_iter)->m_parent))
    {
        while ((Node_t*)_iter != ((Node_t*)_iter)->m_parent->m_left)
        {
            _iter = ((Node_t*)_iter)->m_parent;
        }

        _iter = ((Node_t*)_iter)->m_parent;
    }

    return _iter;    
}

BSTIter_t BSTIterPrev(BSTIter_t _iter)
{
    if (!_iter)
    {
        return NULL;
    }

    if (((Node_t*)_iter)->m_left) 
    {
        _iter = ((Node_t*)_iter)->m_left;

        _iter = GetMostNodeFromSide((Node_t*)_iter, RIGHT);
    }
    else 
    {
        while (_iter != ((Node_t*)_iter)->m_parent->m_right && !BSTIterEqual(_iter, (BSTIter_t)((Node_t*)_iter)->m_parent) )
        {
            _iter = ((Node_t*)_iter)->m_parent;
        }

        _iter = ((Node_t*)_iter)->m_parent;
    }

    if (BSTIterEqual(_iter, (BSTIter_t)((Node_t*)_iter)->m_parent))
    {
        _iter = GetMostNodeFromSide((Node_t*)_iter, LEFT);
    }

    return _iter;    
}

void *BSTIterGet(BSTIter_t _iter)
{
    if (!_iter)
    {
        return NULL;
    }

    return ((Node_t*)_iter)->m_data;
}

void *BSTIterRemove(BSTIter_t _iter)
{
    void *removeIterData = NULL;
    Side_t parentChileSide;

    if (!_iter)
    {
        return NULL;
    }

    if (BSTIterEqual(_iter, (BSTIter_t)((Node_t*)_iter)->m_parent))
    {
        return NULL;
    }

    removeIterData = BSTIterGet(_iter);
    parentChileSide = CheckIterParentChildSide(_iter);

    if (((Node_t*)_iter)->m_left && NULL != ((Node_t*)_iter)->m_right)
    {
        RemoveNodeWith2Children(_iter, parentChileSide);
    }
    else if (((Node_t*)_iter)->m_left)
    {
        RemoveNodeWithRightSonOrLeftSon(_iter, parentChileSide, LEFT);
    }
    else if (((Node_t*)_iter)->m_right)
    {
        RemoveNodeWithRightSonOrLeftSon(_iter, parentChileSide, RIGHT);
    }
    else
    {
        removeLeafNode(_iter, parentChileSide);
    }

    free(_iter);

    return removeIterData;
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static void DestroyNodeRecuAux(Node_t *_node, void (*_nodeDestroy)(void *node))
{
	if (!_node)
	{
		return;
	}

	DestroyNodeRecuAux(_node->m_left, _nodeDestroy);
	DestroyNodeRecuAux(_node->m_right, _nodeDestroy);
	_nodeDestroy(_node);
}

static void InitNode(Node_t *_newNode, void *_data, Node_t *_parent)
{
	_newNode->m_data = _data;
	_newNode->m_parent = _parent;
	_newNode->m_left = NULL;
	_newNode->m_right = NULL;
}

static void MoveNode(BST_t *_bst, Node_t **_nodeRunner, void *_newNodedata, Side_t *_side)
{
    int compareRes = _bst->m_compareFunc((*_nodeRunner)->m_data, _newNodedata);

    switch (compareRes)
    {
        case DUPLICATE_FOUND:
            *_side = DUPLICATED;
            break;

        case GO_LEFT:
            *_nodeRunner = (*_nodeRunner)->m_left;
            *_side = LEFT;
            break;

        case GO_RIGHT:
            *_nodeRunner = (*_nodeRunner)->m_right;
            *_side = RIGHT;
            break;
    }
}

static void nodeSetParent(Node_t *_newNode, Node_t *_parentNode, Side_t _childSide)
{
	if (LEFT == _childSide)
	{
		_parentNode->m_left = _newNode;
	}
	else
	{
        _parentNode->m_right = _newNode;
	}
}

static Node_t *GetMostNodeFromSide(Node_t *_node, Side_t _side)
{
    if (LEFT == _side)
    {
        while (_node->m_left)
        {
            _node = _node->m_left;
        }
    }
    else if (RIGHT == _side)
    {
        while (_node->m_right)
        {
            _node = _node->m_right;
        }
    }

    return _node;
}

static Side_t CheckIterParentChildSide(BSTIter_t _iter)
{
    if ((Node_t*)_iter == ((Node_t*)_iter)->m_parent->m_left)
    {
        return LEFT;
    }
    else
    {
        return RIGHT;
    }
}

static void removeLeafNode(BSTIter_t _iter, Side_t _parentChildSide)
{
    if (_parentChildSide == LEFT)
    {
        ((Node_t*)_iter)->m_parent->m_left = NULL;
    }
    else
    {
        ((Node_t*)_iter)->m_parent->m_right = NULL;
    }
}

static void RemoveNodeWithRightSonOrLeftSon(BSTIter_t _iter, Side_t _parentChildSide, Side_t _childSide)
{
    Node_t *replacmentNode = (_childSide == LEFT) ? ((Node_t*)_iter)->m_left : ((Node_t*)_iter)->m_right;
    Node_t *iterParent = ((Node_t*)_iter)->m_parent;

    if (_parentChildSide == LEFT)
    {
        iterParent->m_left = replacmentNode;
    }
    else
    {
        iterParent->m_right = replacmentNode;
    }

    replacmentNode->m_parent = iterParent;
}

static void RemoveNodeWith2Children(BSTIter_t _iter, Side_t _parentChildSide)
{
    Node_t *replacmentNode = ((Node_t*)_iter)->m_left;
    Node_t *iterParent = ((Node_t*)_iter)->m_parent;
    Node_t *iterRightSubTree = ((Node_t*)_iter)->m_right;
    Node_t *iterLeftSubTree = NULL;
        
    if (replacmentNode->m_right)
    {
        replacmentNode = GetMostNodeFromSide(replacmentNode, RIGHT);
        
        if (replacmentNode->m_left)
        {
            replacmentNode->m_parent->m_right = replacmentNode->m_left;
            replacmentNode->m_left->m_parent =  replacmentNode->m_parent;
        }
        else
        {
            replacmentNode->m_parent->m_right = NULL;
        }

        iterLeftSubTree = ((Node_t*)_iter)->m_left;
        replacmentNode->m_left = iterLeftSubTree;
        iterLeftSubTree->m_parent = replacmentNode;
    }

    if (_parentChildSide == LEFT)
    {
        iterParent->m_left = replacmentNode;
    }
    else
    {
        iterParent->m_right = replacmentNode;
    }

    replacmentNode->m_parent = iterParent;

    replacmentNode->m_right = iterRightSubTree;
    iterRightSubTree->m_parent = replacmentNode;
}

/******************************************************/