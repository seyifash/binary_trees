#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_postorder - function that goes through a binary tree using post-order traversal
 * @tree: the tree to be printed 
 * @func: the function pointer used in printing the tree
 * 
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
    {
        return;
    }
    binary_tree_postorder(tree->left, func);
    binary_tree_postorder(tree->right, func);
    func(tree->n);
}