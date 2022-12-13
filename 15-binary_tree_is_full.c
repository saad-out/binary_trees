#include "binary_trees.h"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/**
 * binary_tree_is_full - checks if a binray tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 (is full) | 0 (not full)
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree && !tree->left && !tree->right)
		return (1);

	return (MIN(binary_tree_is_full(tree->left),
		binary_tree_is_full(tree->right)));
}
