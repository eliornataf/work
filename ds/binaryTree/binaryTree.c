#include <stdlib.h> /* malloc, free */
#include <stdio.h> /* printf, putchar */
#include "binaryTree.h" /* Binary Tree Header */

#define DUPLICATE_FOUND (-1)
#define GO_LEFT (0)
#define GO_RIGHT (1)

/******************************************************/

struct Node
{
	int m_data;
	Node_t *m_left;
	Node_t *m_right;
	Node_t *m_parent;
};

struct BinaryTree
{
	Node_t *m_root;
};

typedef enum ChildSide
{
	LEFT = 0,
	RIGHT = 1,
	NUM_OF_CHILDRENS
} Childside_t;

/*******************************************************
**************** Function Declerations *****************
*******************************************************/

static void DestroyNodeRecuAux(Node_t *node);
static int CompareInt(int nodeData, int inputData);
static Node_t *InitNode(Node_t *newNode, int data, Node_t *parent);
static ADTError_t nodeSetParent(Node_t *newNode, Node_t *parentNode, Childside_t childSide);
static void PreOrderTraverseRecu(Node_t *node);
static void InOrderTraverseRecu(Node_t *node);
static void PostOrderTraverseRecu(Node_t *node);

/*******************************************************
****************** Primary Functions *******************
*******************************************************/

BinaryTree_t *BinaryTreeCreate(void)
{
	BinaryTree_t *binaryTree = (BinaryTree_t*)malloc(sizeof(BinaryTree_t));
	if (!binaryTree)
	{
		return NULL;
	}
	
	binaryTree->m_root = NULL;
	
	return binaryTree;
}

void BinaryTreeDestroy(BinaryTree_t *_binaryTree)
{
	if (!_binaryTree)
	{
		return;
	}
	
	if (_binaryTree->m_root)
	{
		DestroyNodeRecuAux(_binaryTree->m_root);
	}

	free(_binaryTree);
}

ADTError_t BinaryTreeInsert(BinaryTree_t *_binaryTree, int _data)
{
	Node_t *nodeRunner = NULL;
	Node_t *parentRunner = NULL;
	Node_t *newNode = NULL;
	Childside_t childSide = NUM_OF_CHILDRENS;
	ADTError_t status;
	
	if (!_binaryTree)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	newNode = (Node_t*)malloc(sizeof(Node_t));
	if (!newNode)
	{
		return ALLOCATION_FAILED;
	}
	
	if (!_binaryTree->m_root)
	{	
		InitNode(newNode, _data, _binaryTree->m_root);
		if (!newNode)
		{
			return POINTER_NOT_INITIALIZE;
		}
		
		_binaryTree->m_root = newNode;
		
		return OK;
	}
	
	nodeRunner = _binaryTree->m_root;
	
	while (nodeRunner)
	{
		int compareRes = CompareInt(nodeRunner->m_data, _data);
	
		parentRunner = nodeRunner;
		
		if (DUPLICATE_FOUND == compareRes)
		{
			free(newNode);
			return DUPLICATE_DATA;
		}
		else if (GO_LEFT == compareRes)
		{
			nodeRunner = nodeRunner->m_left;
			childSide = LEFT;
		}
		else
		{
			nodeRunner = nodeRunner->m_right;
			childSide = RIGHT;
		}
	}
	
	InitNode(newNode, _data, parentRunner);
	if (!newNode)
	{
		return POINTER_NOT_INITIALIZE;
	}
	
	status = nodeSetParent(newNode, parentRunner, childSide);
	if (OK != status)
	{
		return status;
	}

	return OK;
}

int BinaryTreeIsDataFound(BinaryTree_t *_binaryTree, int _data)
{
	Node_t *nodeRunner = NULL;

	if (!_binaryTree)
	{
		return DATA_IS_NOT_FOUND;
	}
	
	nodeRunner = _binaryTree->m_root;
	
	while (nodeRunner)
	{
		int compareRes = CompareInt(nodeRunner->m_data, _data);
		
		if (DUPLICATE_FOUND == compareRes)
		{
			return DATA_IS_FOUND;
		}
		else if (GO_LEFT == compareRes)
		{
			nodeRunner = nodeRunner->m_left;
		}
		else
		{
			nodeRunner = nodeRunner->m_right;
		}
	}
	
	return DATA_IS_NOT_FOUND;
}

void BinaryTreePrint(BinaryTree_t *_binaryTree, TreeTraverse_t _traverseMode)
{
	if (!_binaryTree || !_binaryTree->m_root)
	{
		return;
	} 
	
	if (PRE_ORDER == _traverseMode)
	{
		PreOrderTraverseRecu(_binaryTree->m_root);
	}
	else if (IN_ORDER == _traverseMode)
	{
		InOrderTraverseRecu(_binaryTree->m_root);
	}
	else if (POST_ORDER == _traverseMode)
	{
		PostOrderTraverseRecu(_binaryTree->m_root);
	}
	
	putchar('\n');
}

/*******************************************************
******************* Static Functions *******************
*******************************************************/

static void DestroyNodeRecuAux(Node_t *_node)
{
	if (!_node)
	{
		return;
	}
	
	DestroyNodeRecuAux(_node->m_left);
	DestroyNodeRecuAux(_node->m_right);
	free(_node);
}

static int CompareInt(int _nodeData, int _inputData)
{
	if (_nodeData == _inputData)
	{
		return DUPLICATE_FOUND;
	}
	
	if (_inputData < _nodeData)
	{
		return GO_LEFT;
	}
	
	return GO_RIGHT;
}

static Node_t *InitNode(Node_t *_newNode, int _data, Node_t *_parent)
{
	_newNode->m_data = _data;
	_newNode->m_parent = _parent;
	_newNode->m_left = NULL;
	_newNode->m_right = NULL;
	
	return _newNode;
}

static ADTError_t nodeSetParent(Node_t *_newNode, Node_t *_parentNode, Childside_t _childSide)
{
	if (_childSide == LEFT)
	{
		_parentNode->m_left = _newNode;
	}
	else
	{
		_parentNode->m_right = _newNode;
	}
	
	return OK;
}

static void PreOrderTraverseRecu(Node_t *_node)
{
	if (!_node)
	{
		return;
	}
	
	printf("%d -> ", _node->m_data);
	PreOrderTraverseRecu(_node->m_left);
	PreOrderTraverseRecu(_node->m_right);
}

static void InOrderTraverseRecu(Node_t *_node)
{
	if (!_node)
	{
		return;
	}
	
	InOrderTraverseRecu(_node->m_left);
	printf("%d -> ", _node->m_data);
	InOrderTraverseRecu(_node->m_right);
}

static void PostOrderTraverseRecu(Node_t *_node)
{
	if (!_node)
	{
		return;
	}
	
	PostOrderTraverseRecu(_node->m_left);
	PostOrderTraverseRecu(_node->m_right);
	printf("%d -> ", _node->m_data);
}

/*****************************************************************************/
