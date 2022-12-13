#include "binary_trees.h"

/**
 * max - return maximum of two positive integers
 * @a: first integer
 * @b: second integer
 *
 * Return: max
 */
size_t max(size_t a, size_t b)
{
	if (a >= b)
		return (a);

	return (b);
}

/**
 * max_nodes - returns max linear nodes in a binary tree
 * @tree: pointer to root of the tree
 *
 * Return: max linear nodes
 */
size_t max_nodes(const binary_tree_t *tree)
{
	size_t left_m, right_m;

	if (!tree)
		return (0);

	left_m = max_nodes(tree->left);
	right_m = max_nodes(tree->right);

	return (max(left_m, right_m) + 1);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to root of the tree
 *
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (max_nodes(tree) - 1);
}
