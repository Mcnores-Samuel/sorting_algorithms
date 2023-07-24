#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp, *a, *c, *b, *d;

	if (*list == NULL || (*list != NULL && (*list)->next == NULL))
		return;

	current = *list;
	while (current != NULL)
	{
		tmp = current->prev;
		while (tmp != NULL && tmp->n > tmp->next->n)
		{
			a = tmp->prev;
			b = tmp;
			c = tmp->next;
			d = tmp->next->next;

			if (a != NULL && b)
			{
				a->next = c;
				c->prev = a;
				c->next = b;
				b->prev = c;
			}
			else
			{
				a = current;
				current->next = tmp;
				*list = a;
			}
			if (d != NULL)
			{
				b->next = d;
				d->prev = b;
			}
			else
				b->next = NULL;
			tmp = c;
			tmp = tmp->prev;
			print_list(*list);
		}
		current = current->next;
	}
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
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
