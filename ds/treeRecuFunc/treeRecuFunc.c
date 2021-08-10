#include <math.h> /* pow */

#define IS_NOT_FULL (0)
#define IS_FULL (1)
#define IS_NOT_SIMILAR (0)
#define IS_SIMILAR (1)
#define TREE_IS_EMPTY (-1)
#define MAX(x, y) ( (x) > (y) > (x) : (y) )
#define IS_NOT_PERFECT_TREE (0)

/**********************************************************/

int ISFullTree(Node_t *_node)
{
	if (NULL == _node) /* tree is empty */
	{
		return IS_FULL;
	}
	
	if (NULL == _node->m_left && NULL == _node->m_right) /* node left & right children are empty */
	{
		return IS_FULL;
	}
	
	if (NULL != _node->m_left && NULL != _node->m_right) /* node left & right children are not empty */ 
	{
		return ( MirrorTreeRecu(_node->m_left) && MirrorTreeRecu(_node->m_right) );
	}
	
	return IS_NOT_FULL; /* node left | right children is not empty & the opposite node is empty*/ 
}

int AreSimilarTrees(Node_t *_nodeTree1, Node_t *_nodeTree2)
{
	if (NULL == _nodeTree1 && NULL == __nodeTree2) /* both empty */
	{
		return IS_SIMILAR;
	}

	if (NULL != _nodeTree1 && NULL != _nodeTree2) /* both non empty */
	{
		return ( AreSimilarTrees(_nodeTree1->m_left, _nodeTree2->m_left) && (_nodeTree1->m_right, _nodeTree2->m_right) );
	}
	
	return IS_NOT_SIMILAR;
}

size_t TreeHeightRecu(Node_t *_node)
{
	if (NULL == _node)
	{
		return TREE_IS_EMPTY;
	}
	
	return (1 + MAX(TreeHeightRecu(_node->m_left), TreeHeightRecu(_node->m_right)) );
}

/*************************************************************************/

static size_t CountNodesRecu(Node_t *_node)
{
	if (!_node)
	{
		return 0;
	}

	return (1 + CountNodesRecu(_node->m_left) + CountNodesRecu(_node->m_right));
}

/*************************************************************************/

int IsPerfectTree(Node_t *_node)
{
	if (!_node)
	{
		return IS_NOT_PERFECT_TREE;
	}

	return ((pow(2, TreeHeight(_node) + 1) - 1) == CountNodesRecu(_node));
}

void MirrorTreeRecu(Node_t *_node) /* Post Order Mirror tree */
{
	Node_t *tempNode = NULL;

	if (!_node)
	{
		return;
	}
	
	MirrorTreeRecu(_node->m_left);
	MirrorTreeRecu(_node->m_right);
	
	tempNode = _node->m_left;
	_node->m_left = _node->m_right;
	_node->m_right = tempNode;
}
