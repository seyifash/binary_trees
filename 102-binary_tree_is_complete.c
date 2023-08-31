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
 * free_queue - frees queue
 * @head: pointer to head
 */

void free_queue(queue_node_t *head)
{
	queue_node_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/**
 * push_into - pushes node to back of queue
 * @head: the pointer to the head
 * @tail: the pointer to tail
 * @node: the node
 */
void push_into(queue_node_t *head, queue_node_t **tail, binary_tree_t *node)
{
	queue_node_t *new_node;

	new_node = create_queue_node(node);
	if (new_node == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = new_node;
	*tail = new_node;
}

/**
 * pop_head - removes head
 * @head: the pointer to head of queue
 */
void pop_head(queue_node_t **head)
{
	queue_node_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}
/**
 * binary_tree_is_complete - Function to check if a binary tree is complete
 * @tree: the tree to check
 * Return: 1 if complete, 0 if not complete
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_node_t *head, *tail;
	int checker = 0;

	if (tree == NULL)
		return (0);

	head = tail = create_queue_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (checker == 1)
			{
				free_queue(head);
				return (0);
			}
			push_into(head, &tail, head->node->left);
		}
		else
			checker = 1;

		if (head->node->right != NULL)
		{
			if (checker == 1)
			{
				free_queue(head);
				return (0);
			}
			push_into(head, &tail, head->node->right);
		}
		else
			checker = 1;

		pop_head(&head);
	}
	return (1);
}
