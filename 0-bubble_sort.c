#include "sort.h"


/**
 * bubble_sort - repeatedly swaps the adjucent elements of the unsorted
 * array into sorted order.
 * @array: an array of integers to sort.
 * @size: the size of the array or Number of elements in the array.
 * Return: nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t pos1;
	int tmp_item, pos2 = 0, bubbled = 0;

	for (pos1 = 0; pos1 < size; pos1++)
	{
		bubbled = 0;
		while (pos2 < size - pos1 - 1)
		{
			tmp_item = array[pos2];
			array[pos2] = array[pos2 + 1];
			array[pos2 + 1] = tmp_item;
			print_array(array, size);
			pos2++;
			bubbled = 1;
		}
		if (bubbled == 0)
			break;
	}
}
