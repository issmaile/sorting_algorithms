#include "sort.h"

/**
 * selection_sort - sorts an array of ints in ascending order
 * using the SelectionSort alg
 * @size: array size
 * @array: array of nums
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, swap, flag = 0;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		tmp = i;
		flag = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[tmp] > array[j])
			{
				tmp = j;
				flag += 1;
			}
		}
		swap = array[i];
		array[i] = array[tmp];
		array[tmp] = swap;
		if (flag != 0)
			print_array(array, size);
	}
}
