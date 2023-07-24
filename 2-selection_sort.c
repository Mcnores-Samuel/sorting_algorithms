#include "sort.h"

/**
 * swaps_values - swaps two values given.
 * @a: first value to swap
 * @b: the second value.
 * Return: nothing.
 */
void swaps_values(int *a, int *b)
{
	int tmp_item = *a;
	*a = *b;
	*b = tmp_item;
}

/**
 * selection_sort - sorts an array of integers in ascending order using
 * the Selection sort algorithm.
 * @array: array to sort.
 * @size: size of the array.
 * Return: nothing;
 */
void selection_sort(int *array, size_t size)
{
	size_t pos = 0, a, b;

	while (pos < size)
	{
		b = pos;
		a = pos + 1;
		while (a < size)
		{
			if (array[a] < array[b])
				b = a;
			a++;
		}

		if (b != pos)
		{
			swaps_values(&array[pos], &array[b]);
			print_array(array, size);
		}
		pos++;
	}
}
