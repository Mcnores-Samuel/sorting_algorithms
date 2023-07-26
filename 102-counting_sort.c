#include "sort.h"

void counting_sort(int *array, size_t size)
{
	int key = array[0], i = 0;

	for (i = 0; i < (int)size; i++)
		if (array[i + 1] > key)
			key = array[i];
	printf("key: %d\n", key);
}


/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    counting_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
