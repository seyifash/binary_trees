#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BSR
 * @value: The value to remove in the BST.
 * Return: A pointer to the new root node after deletion
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
	return (root);

	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
	root->right = bst_remove(root->right, value);
	}
	else
	{
	if (root->left == NULL)
	{
	temp = root->right;
	free(root);
	return (temp);
	}
	else if (root->right == NULL)
	{
	temp = root->left;
	free(root);
	return (temp);
	}
	temp = find_min(root->right);
	root->n = temp->n;
	root->right = bst_remove(root->right, temp->n);
	}
	return (root);

}

/**
 * find_min - finds min value
 * @node: the node to check
 * Return: returns the min node
 */
bst_t *find_min(bst_t *node)
{

	while (node->left != NULL)
	{
		 node = node->left;
	}
	return (node);
}
