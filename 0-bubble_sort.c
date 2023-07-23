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
 * bubble_sort - repeatedly swaps the adjucent elements of the unsorted
 * array into sorted order.
 * @array: an array of integers to sort.
 * @size: the size of the array or Number of elements in the array.
 * Return: nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t pos1, pos2 = 0;
	int bubbled = 0;

	for (pos1 = 0; pos1 < size; pos1++)
	{
		bubbled = 0;
		while (pos2 < size - pos1 - 1)
		{
			if (array[pos2] > array[pos2 + 1])
			{
				swaps_values(&array[pos2], &array[pos2 + 1]);
				print_array(array, size);
				bubbled = 1;
			}
			pos2++;
		}
		pos2 = 0;
		if (bubbled == 0)
			break;
	}
}
