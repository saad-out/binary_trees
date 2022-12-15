#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * resize_queue - creates/resizes the given queue
 * @queue: pointer to given queue
 * @size: pointer to current queue size
 *
 * Return: queue
 */
binary_tree_t **resize_queue(binary_tree_t **queue, size_t *size)
{
	size_t n, i;
	binary_tree_t **new_queue;

	if (!size)
		return (NULL);

	n = *size;
	if (!queue)
	{
		queue = malloc(sizeof(*queue) * n);
		if (!queue)
			return (NULL);
		for (i = 0; i < n; i++)
			queue[i] = NULL;
	}
	else
	{
		new_queue = malloc(sizeof(*new_queue) * (n * 2));
		if (!new_queue)
			return (NULL);

		for (i = 0; i < n; i++)
			new_queue[i] = queue[i];
		for (i = n; i < (n * 2); i++)
			new_queue[i] = NULL;
		n *= 2;
		free(queue);
		queue = new_queue;
	}
	*size = n;

	return (queue);
}

/**
 * binary_tree_levelorder - goes through binary tree in level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *tmp, **queue;
	size_t size, front, rear;

	if (!tree || !func)
		return;
	if (tree && !tree->left && !tree->right)
	{
		func(tree->n);
		return;
	}

	queue = NULL, size = 100;
	queue = resize_queue(queue, &size);
	if (!queue)
		exit(1);

	/* assign root to non-constant pointer */
	if (tree->left)
		tmp = tree->left->parent;
	else
		tmp = tree->right->parent;

	front = rear = 0;
	while (tmp)
	{
		func(tmp->n);
		if (tmp->left)
			queue[rear++] = tmp->left;
		if (tmp->right)
			queue[rear++] = tmp->right;

		tmp = queue[front++];
		if ((rear + 1) >= size)
		{
			queue = resize_queue(queue, &size);
			if (!queue)
				free(queue), exit(1);
		}
	}
	free(queue);
}
