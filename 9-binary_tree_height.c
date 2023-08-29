#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_height -  function that measures the height of a binary tree
 * @tree: the tree whose height is to be returned
 * Return: the height of the true else 0.
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left, height_right;

	if (tree == NULL)
	return (0);

	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_right = tree->right ? 1 +  binary_tree_height(tree->right) : 0;
	return (height_left > height_right ? height_left : height_right);

}
