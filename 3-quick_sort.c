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
 * quick_partion_set - rearrange elements in an array around a pivot element.
 * It uses lomuto partitioning scheme.
 * @array: array to sort
 * @size: size of the array.
 * @low_b: elements in the left side of the pivot.
 * @upper_b: elements in the right side of the pivot element.
 * Return: Number representing the upper bound position of the previous
 * sort.
 */
int quick_partion_set(int *array, int size,  int low_b, int upper_b)
{
	int pivot = upper_b, start = low_b, start_next = low_b;

	while (start_next < upper_b)
	{
		if (array[start_next] < array[pivot])
		{
			if (start < start_next)
			{
				swaps_values(&array[start_next], &array[start]);
				print_array(array, size);
			}
			start++;
		}
		start_next++;
	}
	if (array[start] > array[pivot])
	{
		swaps_values(&array[start], &array[pivot]);
		print_array(array, size);
	}
	return (start);
}

/**
 * quick_sort_set1 - recursively calls itself till all elements are
 * sorted.
 * @array: array to sort
 * @size: size of the array.
 * @low_b: elements in the left side of the pivot.
 * @upper_b: elements in the right side of the pivot element.
 * Return: Number representing the upper bound position of the previous
 * sort.
 */
void quick_sort_set1(int *array, int size, int low, int upper)
{
	int n;

	if (low < upper)
	{
		n = quick_partion_set(array, size, low, upper);
		quick_sort_set1(array, size, low, n - 1);
		quick_sort_set1(array, size, n + 1, upper);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: an array to sort
 * @size: size of the array or represents Number of elements.
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;

	quick_sort_set1(array, size, 0, size - 1);
}
