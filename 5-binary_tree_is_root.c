#include <stdlib.h>
#include "binary_trees.h"
/**
 * binary_tree_is_root - checks if a given node is a root node
 * @node: the node to be checked
 * Return: returns 1 if its a parent node and 0 otherwise
*/
int binary_tree_is_root(const binary_tree_t *node)
{
    if (node != NULL && node->parent == NULL)
    {
        return (1);
    }
        return (0);
}