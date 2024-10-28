#include "sort.h"

/**
* insertion_sort_list - sorts a list using insertion alg.
* @list: list to sort.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next_node, *insert;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		next_node = current->next;
		insert = current->prev;

		while (insert && current->n < insert->n)
		{
			swap_nodes(list, &insert, current);
			print_list((const listint_t *)*list);
		}
		current = next_node;
	}
}

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list.
 * @list: Double pointer to the head of the list.
 * @n1: Double pointer to the first node to swap.
 * @n2: Pointer to the second node to swap.
 */
void swap_nodes(listint_t **list, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next)
		n2->next->prev = *n1;

	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev)
		(*n1)->prev->next = n2;
	else
		*list = n2;

	(*n1)->prev = n2;
	*n1 = n2->prev;
}
