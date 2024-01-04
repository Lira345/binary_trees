#include "binary_trees.h"

/**
 * bst_insert - Inserts the nodes in order to recreate the binary search tree
 * @tree: Pointer to create with type binary search tree
 * @value: Pointer to the value of the node to be inserted
 * Return: Binary Search Tree.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;
	bst_t *tmp;
	binary_tree_t *aux;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		aux = binary_tree_node((binary_tree_t *)(*tree), value);
		new = (bst_t *)aux;
		*tree = new;
	}
	else
	{
		tmp = *tree;
		if (value < tmp->n)
		{
			if (tmp->left)
				new = bst_insert(&tmp->left, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)temp, value);
				new = tmp->left = (bst_t *)aux;
			}
		}
		else if (value > tmp->n)
		{
			if (tmp->right)
				new = bst_insert(&tmp->right, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)tmp, value);
				new = tmp->right = aux;
			}
		}
		else
			return (NULL);
	}
	return (new);
}
