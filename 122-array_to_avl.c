#include "binary_trees.h"
/**
 *  array_to_avl - turns the array to a avl tree
 *  @array: array to turns to AVL tree
 *  @size: size of array
 *  Return: AVL tree from array
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t m, n = 0;
	avl_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (m = 0; m < size; m++)
	{
		for (n = 0; n < m; n++)
		{
			if (array[n] == array[m])
				break;
		}
		if (n == m)
		{
			if (avl_insert(&root, array[m]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (root);
}
