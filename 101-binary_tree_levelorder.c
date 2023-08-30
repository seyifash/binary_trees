#include <stddef.h>
#include <stdio.h>
#include "binary_trees.h"
#include <stdlib.h>

/**
 * create_queue_node- creates queqe node
 * @node: the node to be created
 * Return: the new node
 */
queue_node_t *create_queue_node(binary_tree_t *node)
{
	queue_node_t *new_node;

	new_node = malloc(sizeof(queue_node_t));
	if (new_node == NULL)
	{
	return (NULL);
	}
	new_node->node = node;
	new_node->next = NULL;
	return (new_node);
}

/**
 * create_queue - Function to create an empty queue
 * Return: the initailised node
 */
queue_t *create_queue()
{
	queue_t *queue;

	queue = malloc(sizeof(queue_t));
	if (queue == NULL)
	{
	return (NULL);
	}
	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}

/**
 * enqueue - Function to enqueue a node in the queue
 * @queue: the queue
 * @node: the nodde
 */

void enqueue(queue_t *queue, binary_tree_t *node)
{
	queue_node_t *new_node = create_queue_node(node);

	if (new_node == NULL)
	{
	return;
	}

	if (queue->rear == NULL)
	{
	queue->front = new_node;
	queue->rear = new_node;
	return;
	}

	queue->rear->next = new_node;
	queue->rear = new_node;
}
/**
 * dequeue - Function to dequeue a node from the queue
 * @queue: the queue
 * Return: the node
 */
binary_tree_t *dequeue(queue_t *queue)
{
	queue_node_t *temp;
	binary_tree_t *node;

	if (queue->front == NULL)
	{
	return (NULL);
	}

	temp = queue->front;
	node = temp->node;
	queue->front = queue->front->next;

	if (queue->front == NULL)
	{
	queue->rear = NULL;
	}

	free(temp);
	return (node);
}
/**
 * binary_tree_levelorder - goes through binary tree using level-order t
 * @tree: the tree
 * @func: a pointer to a function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue;
	binary_tree_t *current;

	if (tree == NULL || func == NULL)
	{
	return;
	}

	queue = create_queue();
	if (queue == NULL)
	{
	return;
	}

	enqueue(queue, (binary_tree_t *)tree);

	while (queue->front != NULL)
	{
	current = dequeue(queue);
	func(current->n);

	if (current->left != NULL)
	{
	enqueue(queue, current->left);
	}

	if (current->right != NULL)
	{
	enqueue(queue, current->right);
	}
	}

	free(queue);
}
