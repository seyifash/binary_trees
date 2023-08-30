#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * create_queue_node - creates a queue
 * @node: the node
 * Return: returns the created node
 */

queue_node_t *create_queue_node(const binary_tree_t *node)
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
 * create_queue - the creation of a new node
 * Return: the new node
 */

queue_t *create_queue()
{
	queue_t *queue;

	queue = malloc(sizeof(queue_t));
	if (queue == NULL)
	{
	return (NULL);
	}
	queue->front = queue->rear = NULL;
	return (queue);
}

/**
 * enqueue - enqueues the node in the queue
 * @queue: the pointer to the queue
 * @node: the node
 */
void enqueue(queue_t *queue, const binary_tree_t *node)
{
	queue_node_t *new_node;

	new_node = create_queue_node(node);
	if (new_node == NULL)
	{
	return;
	}

	if (queue->rear == NULL)
	{
	queue->front = queue->rear = new_node;
	return;
	}

	queue->rear->next = new_node;
	queue->rear = new_node;
}

/**
 * dequeue - Function to dequeue a node from the queue
 * @queue: the queue
 * Return: the dequeue node
 */
const binary_tree_t *dequeue(queue_t *queue)
{
	const binary_tree_t *node;
	queue_node_t *temp;

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
 * binary_tree_is_complete - Function to check if a binary tree is complete
 * @tree: the tree to check
 * Return: 1 if complete, 0 if not complete
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *queue;
	int reached_null;
	const binary_tree_t *current;

	if (tree == NULL)
	{
	return (0);
	}

	queue = create_queue();
	reached_null = 0;

	enqueue(queue, tree);

	while (queue->front != NULL)
	{
	current = dequeue(queue);
	if (current == NULL)
	{
	reached_null = 1;
	}
	else
	{
	if (reached_null)
	{
	free(queue);
	return (0);
	}

	enqueue(queue, current->left);
	enqueue(queue, current->right);
	}
	}
	free(queue);
	return (1);
}
