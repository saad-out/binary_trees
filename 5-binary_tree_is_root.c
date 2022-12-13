#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a node is root
 * @node: node to be checked
 *
 * Return: 1 (is root) | 0 (not root)
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node && !node->parent)
		return (1);

	return (0);
}
