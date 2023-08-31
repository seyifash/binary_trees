#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdbool.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;
typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;


/**
 * struct queue_node - a queue node
 * @node: the node pointer
 * @next: pointer to the next node
 */
typedef struct queue_node
{
	const binary_tree_t *node;
	struct queue_node *next;
} queue_node_t;

/**
 * struct queue - the struct for the queue
 * @front: the front node
 * @rear: the rear node
 */
typedef struct queue
{
	queue_node_t *front;
	queue_node_t *rear;
} queue_t;
queue_node_t *create_queue_node(const binary_tree_t *node);
queue_t *create_queue();
void enqueue(queue_t *queue, const binary_tree_t *node);
const binary_tree_t *dequeue(queue_t *queue);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
bool is_valid_bst(const binary_tree_t *tree, int min, int max);
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
int binary_tree_is_leaf(const binary_tree_t *node);
bst_t *array_to_bst(int *array, size_t size);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int max(int a, int b);
int tree_height(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
bool is_perfect(const binary_tree_t *tree, int d, int level);
int depth(const binary_tree_t *tree);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *secoond);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *find_min(bst_t *node);
bst_t *bst_remove(bst_t *root, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_insert(bst_t **tree, int value);
int binary_tree_is_bst(const binary_tree_t *tree);
#endif
