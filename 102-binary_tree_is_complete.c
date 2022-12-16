#include <stdio.h>
#include "binary_trees.h"

/**
 * count_nodes - counts the number of nodes in a binary tree
 * @tree: pointer to root node of the binary tree
 *
 * Return: number of nodes
 */
size_t count_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * bt_is_complete - check if a binary tree is complete recursively
 * @tree: pointer to root node of the binary tree
 * @i: node index in the array of nodes
 * @n: number of nodes in the binary tree
 *
 * Return: 1 (is complete) | 0 (not complete)
 */
int bt_is_complete(const binary_tree_t *tree, size_t i, size_t n)
{
	if (!tree)
		return (1);

	if (i >= n)
		return (0);

	return (bt_is_complete(tree->left, (2 * i) + 1, n) &&
		bt_is_complete(tree->right, (2 * i) + 2, n));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer ot the root node of the tree to check
 *
 * Return: 1 (is complete) | 0 (not complete)
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t number_of_nodes;

	if (!tree)
		return (0);

	number_of_nodes = count_nodes(tree);

	return (bt_is_complete(tree, 0, number_of_nodes));
}
