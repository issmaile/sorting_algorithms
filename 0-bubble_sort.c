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
	size_t j, i, tmp = 0;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (array[j + 1] && array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
