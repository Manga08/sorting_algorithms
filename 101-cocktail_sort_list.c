#include "sort.h"
/**
 * swap - Swap nodes.
 * @temp: Temporal variable to swap the nodes.
 * @temp2: Another temporal variable to swap the nodes.
 * @list: The list to sort.
 **/
void swap(listint_t *temp, listint_t *temp2, listint_t **list)
{
	listint_t *left_node, *right_node;

	left_node = temp->prev;
	right_node = temp2->next;

	if (left_node != NULL)
		left_node->next = temp2;
	else
		*list = temp2;

	if (right_node != NULL)
		right_node->prev = temp;

	temp2->prev = left_node;
	temp->next = right_node;
	temp2->next = temp;
	temp->prev = temp2;
	print_list(*list);
}
/**
 * cocktail_sort_list -  sorts a doubly linked list by the Cocktail sort.
 * @list: The list to sort.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *aux;
	int handler = 1;

	if (list == NULL || (*list)->next == NULL || *list == NULL)
		return;

	aux = *list;

	while (handler)
	{
		handler = 0;
		while (aux->next != NULL)
		{
			if (aux->n > aux->next->n)
			{
				swap(aux, aux->next, list);
				++handler;
				continue;
			}
			aux = aux->next;
		}
		aux = aux->prev;
		while (aux->prev != NULL)
		{
			if (aux->n < aux->prev->n)
			{
				swap(aux->prev, aux, list);
				++handler;
				continue;
			}
			aux = aux->prev;
		}
	}
}
