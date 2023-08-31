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
	return (bst_recursive(root, root, value));
}
/**
 * bst_recursive - Removes a node from a binary search tree recursively.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @node: A pointer to the current node in the BST.
 * @value: The value to remove from the BST.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *bst_recursive(bst_t *root, bst_t *node, int value)
{

	if (node != NULL)
	{
	if (node->n == value)
	return (delete(root, node));
	if (node->n > value)
	return (bst_recursive(root, node->left, value));
		return (bst_recursive(root, node->right, value));
	}
	return (NULL);
}
/**
 * delete -  deletes the node that has the given value
 * @root: the root node
 * @node: the node to be deleted
 * Return: the new node after deletion
 */
bst_t *delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	/* No children or right-child only */
	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	/* Left-child only */
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	/* Two children */
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (delete(root, successor));
}
/**
 * inorder_successor - Returns the minimum value of a binary search tree.
 * @root: A pointer to the root node of the BST to search.
 *
 * Return: The minimum value in @tree.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}
