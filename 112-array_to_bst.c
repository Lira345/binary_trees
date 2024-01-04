#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: BST tree from array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t m = 0;
	bst_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; m < size; m++)
	{
		if (m == 0)
		{
			bst_insert(&root, array[m]);
		}
		else
		{
			bst_insert(&root, array[m]);
		}
	}
	return (root);
}
