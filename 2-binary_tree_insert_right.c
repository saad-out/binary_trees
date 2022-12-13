#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the left-right of another node
 * @parent: pointer to parent node
 * @value: new node's value
 *
 * Return: pointer to new node (Success) | NULL (Failure)
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;

	if (parent->right)
		parent->right->parent = new_node;
	new_node->right = parent->right;
	parent->right = new_node;

	return (new_node);
}
