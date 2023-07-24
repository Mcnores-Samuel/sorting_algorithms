#include "sort.h"

/**
 * swap_list - swaps specified node in a linked list.
 * @list: double to the list at which nodes are to be swapped.
 * @first_node: double pointer to the first_node
 * @second_node: pointer to the second node to swap.
 * Return: void.
 */
void swap_list(listint_t **list, listint_t **first_node,
		listint_t *second_node)
{
	(*first_node)->next = second_node->next;
	if (second_node->next != NULL)
		second_node->next->prev = *first_node;
	second_node->prev = (*first_node)->prev;
	second_node->next = *first_node;
	if ((*first_node)->prev != NULL)
		(*first_node)->prev->next = second_node;
	else
		*list = second_node;
	(*first_node)->prev = second_node;
	*first_node = second_node->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm;
 * @list: double pointer to the list to be sorted.
 * Return: nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp, *tmp_prev;

	if (*list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		tmp = current->next;
		tmp_prev = current->prev;
		while (tmp_prev != NULL && current->n < tmp_prev->n)
		{
			swap_list(list, &tmp_prev, current);
			print_list(*list);

		}
		current = tmp;
	}
}
