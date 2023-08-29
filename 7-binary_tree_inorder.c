#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_inorder - function that goes through a binary tree by pre-order
 * @tree: the tree to be printed
 * @func: the function pointer used in printing the tree
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
	return;
	}
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
