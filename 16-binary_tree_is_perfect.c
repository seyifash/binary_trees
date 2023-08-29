#include <stdbool.h>
#include <stddef.h>
#include "binary_trees.h"

/**
 * depth - calculates the depth of the tree
 * @tree: the tree to ba calculated
 * Return: returns the depth of the tree
 */
int depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree != NULL)
	{
	d++;
	tree = tree->left;
	}
	return (d);
}
/**
 * is_perfect - checks if the tree is perfect
 * @tree: the tree to be checked
 * @d: the depth
 * @level: the level to be checked
 * Return: true of false
 */
bool is_perfect(const binary_tree_t *tree, int d, int level)
{
	if (tree == NULL)
	return (true);

	if (tree->left == NULL && tree->right == NULL)
	return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
	return (false);

	return (is_perfect(tree->left, d, level + 1) &&
	is_perfect(tree->right, d, level + 1));
}
/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: the tree to be checked
 * Return: 1 if its persfect and 0 if not
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	d = depth(tree);
	return (is_perfect(tree, d, 0));
}
