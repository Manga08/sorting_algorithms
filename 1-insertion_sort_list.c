#include "sort.h"

/**
 * insertion_sort_list - that sorts a doubly linked list
 * of integers in ascending order using the
 * Insertion sort algorithm
 * @list: lis ot sort
 * Return: None
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *aux = *list, *handler = aux;

	if (!list || !*list || !(*list)->next)
		return;

	while (aux)
	{
		handler = aux;
		while (handler->prev && (handler->prev->n > handler->n))
		{
			handler->prev->next = handler->next;
			if (handler->next)
				handler->next->prev = handler->prev;
			handler->next = handler->prev;
			handler->prev = handler->next->prev;
			handler->next->prev = handler;
			if (handler->prev)
				handler->prev->next = handler;
			else
				*list = handler;
			print_list(*list);
		}
		aux = aux->next;
	}
}
