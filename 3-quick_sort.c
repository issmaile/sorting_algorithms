#include "sort.h"

/**
 * swap - swaps positions of 2 elements in an array
 * @array: array
 * @i1: item 1
 * @i2: item 2
 *
 * Return: void
 */
void swap(int *array, ssize_t i1, ssize_t i2)
{
	int t;

	t = array[i1];
	array[i1] = array[i2];
	array[i2] = t;
}

/**
 * lp - lomuton partion implementation
 * @array: array
 * @first: first elmt in array
 * @last: last elemnt in array
 * @size: array size
 *
 * Return: return the pos of last sorted element
 */
int lp(int *array, ssize_t first, ssize_t last, ssize_t size)
{
	int piv = array[last];
	ssize_t finder, current = first;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < piv)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}

	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}

	return (current);
}

/**
 * qs - qs alg
 * @array: array
 * @first: first el
 * @last: last el
 * @size: size of array
 *
 * Return: void
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t pos = 0;

	if (first < last)
	{
		pos = lp(array, first, last, size);

		qs(array, first, pos - 1, size);
		qs(array, pos + 1, last, size);
	}
}

/**
 * quick_sort - quick sort algorithm
 * @array: array
 * @size: size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	qs(array, 0, size - 1, size);
}
