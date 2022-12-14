#include "binary_trees.h"

/**
 * find_depth - finds depth of leftmost node in binary tree
 * @tree: pointer to root of the tree
 *
 * Return: depth
 */
size_t find_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + find_depth(tree->left));
}

/**
 * bt_is_perfect - helper function to check if binary tree is perfect
 * @tree: pointer to root node of the tree to check
 * @depth: depth of leftmost leave
 * @level: current level depth
 *
 * Return: 1 (is perfect) | 0 (not perfect)
 */
int bt_is_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (!tree)
		return (1);

	if (tree && !tree->left && !tree->right)
		if (depth == level)
			return (1);
	if (tree && (!tree->left || !tree->right))
		return (0);

	return (bt_is_perfect(tree->left, depth, level + 1) &&
		bt_is_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 (is perfect) | 0 (not perfect)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (0);

	depth = find_depth(tree) - 1;

	return (bt_is_perfect(tree, depth, 0));
}
