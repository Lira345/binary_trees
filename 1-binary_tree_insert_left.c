#include "binary_trees.h"

/**
 * binary_tree_insert_left - Addd a node in the left of the parent node,
 * if it exists it moves down one level and adds a new node first.
 * @parent: parent node of a specified node.
 * @value: The value of the node.
 * Return: if fails (NULL) or the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
	{
		return (NULL);
	}
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
	{
		return (NULL);
	}
	if (parent->left != NULL)
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
	}
	parent->left = new_node;
	return (new_node);
}
