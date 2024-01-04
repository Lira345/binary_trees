#include "binary_trees.h"

/**
 * check_sub_tree_Left -This function checks if the nodes are small than
 * roots specified.
 * @node: Pointer to the node in tree to verify condition
 * @max: the maximum value to compare
 *
 * Return: if all nodes are similar 1 or equal or 0 if not
 */
int check_sub_tree_Left(const binary_tree_t *node, int max)
{
	int left = 0;
	int right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= max)
			return (0);
		left = check_sub_tree_Left(node->left, max);
		right = check_sub_tree_Left(node->right, max);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}

/**
 * check_sub_tree_Right - Checks if the nodes are bigger than the
 * roots specified
 * @node: Pointer to the node in tree to verify condition
 * @min: the minimum value to compare
 *
 * Return: 1 if all is bigger or equal or 0 if not
 */
int check_sub_tree_Right(const binary_tree_t *node, int min)
{
	int left = 0;
	int right = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= min)
			return (0);
		left = check_sub_tree_Right(node->left, min);
		right = check_sub_tree_Right(node->right, min);
		if (left == right && left == 1)
			return (1);
		return (0);
	}
}

/**
 * binary_tree_is_bst -  checks if a binary tree is a valid Binary Search Tree
 * The left subtree of a node contains only nodes with values less than.
 * The right subtree of a node contains only nodes with values greater than.
 * The left and right subtree each must also be a binary search tree
 * There must be no duplicate values
 * @tree:  a pointer to the root node of the tree to check
 * Return: 1 if it is a BST or 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int right = 2;
	int left = 2;
	int var = 0;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		var = check_sub_tree_Left(tree->left, tree->n);
		if (var == 0)
			return (0);
		left = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		var = check_sub_tree_Right(tree->right, tree->n);
		if (var == 0)
			return (0);
		right = binary_tree_is_bst(tree->right);
	}
	if (left != 2 || right != 2)
	{
		if (left == 0 || right == 0)
			return (0);
	}
	return (1);
}
