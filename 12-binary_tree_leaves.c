#include "binary_trees.h"
/**
 * binary_tree_leaves - Function that returns the number of leaves in a tree
 * @tree: tree to check
 * Return: number of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0, m = 0, n = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		m = binary_tree_leaves(tree->left);
		n = binary_tree_leaves(tree->right);
		leaf = m + n;
		return ((!m && !n) ? leaf + 1 : leaf + 0);
	}
}
