#include <stdio.h>
#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_size - function that calculates the sizes of a binary tree
 * @tree: the tree whose size is to be calculated
 * Return: returns the size of the tree
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
