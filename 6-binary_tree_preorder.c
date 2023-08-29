#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_preorder - function that goes through a binary tree using pre-order traversal
 * @tree: the tree to be printed 
 * @func: the function pointer used in printing the tree
 * 
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
    {
        return;
    }
    func(tree->n);
    binary_tree_preorder(tree->left, func);
    binary_tree_preorder(tree->right, func);
}