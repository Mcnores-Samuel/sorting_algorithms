#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);
int quick_partion_set(int *array, int size,  int low_b, int upper_b);
void quick_sort_set1(int *array, int size, int low, int upper);
void swaps_values(int *a, int *b);

void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);

#endif
