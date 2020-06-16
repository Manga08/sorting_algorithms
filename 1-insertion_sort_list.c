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
	listint_t *aux, *handler;

	if (!list || !*list || !(*list)->next)
		return;

	handler = aux = (*list)->next;

	while (aux)
	{
		aux = aux->next;
		while (handler->prev && handler->n < handler->prev->n)
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
		handler = aux;
	}
}
