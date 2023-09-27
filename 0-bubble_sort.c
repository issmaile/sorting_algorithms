#include "sort.h"

/**
 * bubble_sort - sort array els from min to max val
 * @array: array to sort
 * @size: array size
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n = 0, newn = 0, tmp = 0;

	n = size;

	if (size < 2)
		return;

	while (n > 1)
	{
		for (i = 1; i < n; i++)
		{
			if (array[i - 1] && array[i] && array[i - 1] > array[i])
			{
				tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				newn = i;
				print_array(array, size);
			}
		}
		n = newn;
	}
}
