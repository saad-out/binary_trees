#include "binary_trees.h"

/**
 * to_root - stores the path from a node to the root in an array
 * @node: given node
 * @array: array to store path in
 * @size: array size
 *
 * Return: size
 */
size_t to_root(const binary_tree_t *node, binary_tree_t **array, size_t size)
{
	size_t i;
	binary_tree_t *tmp;

	if (!node || !array)
		return (0);

	i = 0, tmp = node->parent;
	while (tmp && i < size)
	{
		array[i++] = tmp;
		tmp = tmp->parent;
	}

	return (--i);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 *
 * Return: pointer to LCA if exists
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *f_path[100];
	binary_tree_t *s_path[100];
	size_t i, j;

	if (!first || !second)
		return (NULL);

	if (first->parent == second)
		return (first->parent);
	if (second->parent == first)
		return (second->parent);

	i = to_root(first, f_path, 100), j = to_root(second, s_path, 100);

	while (f_path[i] == s_path[j])
		i--, j--;

	return (f_path[i + 1]);
}
