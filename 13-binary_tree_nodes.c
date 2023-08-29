#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_nodes -  function that counts the node with a child
 * @tree: the tree whose child is to be counted
 * Return: returns the number of node with at least one child
*/

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
	return (0);

	if (tree->left != NULL || tree->right != NULL)
	{
	count = 1;
	}

	count += binary_tree_nodes(tree->left);
	count += binary_tree_nodes(tree->right);

	return (count);
}
