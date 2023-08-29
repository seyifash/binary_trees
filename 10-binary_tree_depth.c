#include <stdio.h>
#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_depth - function that calculates the depth of a binary tree
 * @tree: the tree whose depthis to be calculated
 * Return: returns the depth of the tree
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
	return (0);

	while (tree->parent != NULL)
	{
	tree = tree->parent;
	depth++;
	}
	return (depth);
}
