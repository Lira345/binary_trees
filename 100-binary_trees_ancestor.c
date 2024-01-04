#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that checks an ancestor
 * @first: First node
 * @second: Second node
 * Return: the node of the ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *k, *o;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	k = first->parent;
	o = second->parent;
	if (k == NULL || first == o || (!k->parent && o))
	{
		return (binary_trees_ancestor(first, o));
	}
	else if (o == NULL || k == second || (!o->parent && k))
	{
		return (binary_trees_ancestor(k, second));
	}
	return (binary_trees_ancestor(k, o));
}
