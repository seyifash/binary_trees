#include <stdio.h>
#include "binary_trees.h"
#include <stdlib.h>
/**
 * binary_tree_leaves - function that calculates the leaf of a binary tree
 * @tree: the tree whose leaf is to be calculated
 * Return: returns the leaf of the tree
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{

	if (tree == NULL)
	{
	return (0);
	}
	if (tree->left == NULL && tree->right == NULL)
	return (1);
	else
	{
	return  (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
	}
}
