#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * max - calculates the maximum nymber
 * @a: the first integer
 * @b: the second integer
 * Return: the height
 */
int max(int a, int b)
{
	return ((a > b) ? a : b);
}

/**
 * tree_height - calculates the tree height
 * @tree: the tree to be calculated
 * Return: the height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
	{
	return (0);
	}

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);
	return (1 + max(left_height, right_height));
}


/**
 * binary_tree_balance - function that measures the balance factor of a b tree
 * @tree: the tree to ba calculated
 * Return: returns 0 on succees
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
	{
	return (0);
	}
	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return (left_height - right_height);
}
