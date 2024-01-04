#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of the binary tree
 * @tree: Pointer to the root of the tree
 * Return: The height measured
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t m = 0;
	size_t n = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			m = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			n = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((m > n) ? m : n);
	}
}

/**
 * bal_avl - The auxiliar process to compare the subtree's if AVL
 * @tree: Pointer to the node that points the tree check
 * @high: The node thet point to the higher node
 * @lower: The node that point to the lower node
 * Return: Return: 1 if tree is AVL, 0 if not.
 */
int bal_avl(const binary_tree_t *tree, int lower, int high)
{
	size_t height_m;
	size_t height_n, balancer;

	if (tree != NULL)
	{
		if (tree->n > high || tree->n < lower)
		{
			return (0);
		}
		height_m = binary_tree_height(tree->left);
		height_n = binary_tree_height(tree->right);
		balancer = height_m > height_n ? height_m - height_n : height_n - height_m;
		if (balancer > 1)
		{
			return (0);
		}
		return (bal_avl(tree->left, lower, tree->n - 1) &&
				bal_avl(tree->right, tree->n + 1, high));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks if the binary tree is a valid AVL tree.
 * @tree: node that point to the tree to check.
 * Return: 1 if tree is AVL, 0 if not.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (bal_avl(tree, INT_MIN, INT_MAX));
}
