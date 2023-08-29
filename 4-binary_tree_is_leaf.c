#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_leaf - function that checks if a node is a leaf
 * @node: the node to be checked
 * Return: returns 1 if its a leaf node, else returns 0
*/

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
	return (1);

	return (0);
}




