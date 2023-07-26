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

void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *forward, *backward, *temp, *second;
	int cocktail = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;

	while (current != NULL)
	{
		forward = current;
		while (forward != NULL && forward->n > forward->next->n)
		{
			temp = forward->prev;
			second = forward->next;

			forward->next = second->next;
			second->next = forward;
			if (second->next != NULL)
				second->next->prev = forward;
			forward->prev = second;
			if (temp != NULL)
				temp->next = second;
			else
				*list = second;
			second->prev = temp;
			forward = second->next;

			cocktail = 1;
			forward = forward->next;
			print_list(*list);
		}
		cocktail = 0;
		backward = forward->prev;

		while (backward != NULL && backward->n < backward->prev->n)
		{
			swap_list(list, &backward, backward->next);
			cocktail = 1;
			backward = backward->prev;
		}

		if (cocktail == 0)
			break;
		current = current->next;
	}
}

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    cocktail_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
