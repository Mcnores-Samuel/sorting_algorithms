#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence
 * @array: an array to sort
 * @size: Number elements in the array
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int interval = 0, out_pos, in_pos, tmp;

	if (size < 2)
		return;
	while (interval < (int)size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		out_pos = interval;
		while (out_pos < (int)size)
		{
			tmp = array[out_pos];
			in_pos = out_pos;
			while (in_pos > interval - 1 &&
					array[in_pos - interval] >= tmp)
			{
				array[in_pos] = array[in_pos - interval];
				in_pos = in_pos - interval;
			}
			array[in_pos] = tmp;
			out_pos++;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
